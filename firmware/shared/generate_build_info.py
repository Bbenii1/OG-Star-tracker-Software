import json
import os
import shutil
from datetime import datetime, timezone

Import("env")

def generate_build_info(target, source, env):
    """Generate a JSON file with build information and collect all build
    artifacts (bootloader, partitions, firmware binary) into a single
    per-build output folder under build/."""

    my_flags = env.ParseFlags(env["BUILD_FLAGS"])
    defines = dict()
    for b in my_flags.get("CPPDEFINES"):
        if isinstance(b, list):
            defines[b[0]] = b[1]
        else:
            defines[b] = b

    name = str(defines.get("NAME", "unknown")).strip('"')
    binary_name = str(defines.get("BINARY_NAME", "unknown")).strip('"')
    firmware_version = str(defines.get("FIRMWARE_VERSION", "unknown")).strip('"')
    interface_version = str(defines.get("INTERFACE_VERSION", "unknown")).strip('"')
    stepper_suffix = str(defines.get("STEPPER_SUFFIX", "")).strip('"')
    hemisphere = str(defines.get("c_DIRECTION", "")).strip('"')
    wifi_ssid = str(defines.get("WIFI_SSID", "")).strip("'\"")
    wifi_password = str(defines.get("WIFI_PASSWORD", "")).strip("'\"")
    mdns_name = str(defines.get("MDNS_NAME", "")).strip("'\"")
    webserver_port = int(defines.get("WEBSERVER_PORT", 80))

    # Determine stepper details from suffix
    if stepper_suffix == "09deg":
        stepper_type = "0.9deg"
    elif stepper_suffix == "18deg":
        stepper_type = "1.8deg"
    else:
        stepper_type = "unknown"
    if hemisphere == "1":
        hemisphere = "north"
    else:
        hemisphere = "south"

    # Build the full binary name
    if stepper_suffix:
        full_binary_name = "%s_v%s_%s_%s" % (binary_name, firmware_version, stepper_type, hemisphere)
    else:
        full_binary_name = "%s_v%s_%s" % (binary_name, firmware_version, hemisphere)

    build_info = {
        "name": name,
        "firmware_version": firmware_version,
        "interface_version": interface_version,
        "stepper_type": stepper_type,
        "hemisphere": hemisphere,
        "wifi_mode": "AP",
        "wifi_ssid": wifi_ssid,
        "wifi_password": wifi_password,
        "mdns_name": mdns_name,
        "webserver_port": webserver_port,
        "build_date": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "build_type": env.get("BUILD_TYPE", "release"),
        "binary_name": full_binary_name,
        "builds": [
            {
                "chipFamily": "ESP32",
                "parts": [
                    {"path": "bootloader.bin", "offset": 4096},
                    {"path": "partitions.bin", "offset": 32768},
                    {"path": "%s.bin" % full_binary_name, "offset": 65536},
                ],
            }
        ],
    }

    # --- Create per-build output folder: build/<full_binary_name>/ ---
    project_dir = env["PROJECT_DIR"]
    build_output_dir = os.path.join(project_dir, "build", full_binary_name)
    os.makedirs(build_output_dir, exist_ok=True)

    # Write the JSON build-info file
    json_path = os.path.join(build_output_dir, "%s.json" % full_binary_name)
    with open(json_path, "w") as f:
        json.dump(build_info, f, indent=2)
    print("Build info written to: %s" % json_path)

    # --- Copy build artifacts from .pio/build/<env>/ into the output folder ---
    pio_build_dir = env.subst("$BUILD_DIR")  # .pio/build/<env_name>

    artifacts = {
        "bootloader.bin": "bootloader.bin",
        "partitions.bin": "partitions.bin",
        "%s.bin" % full_binary_name: "%s.bin" % full_binary_name,
    }

    for src_name, dst_name in artifacts.items():
        src_path = os.path.join(pio_build_dir, src_name)
        dst_path = os.path.join(build_output_dir, dst_name)
        if os.path.isfile(src_path):
            shutil.copy2(src_path, dst_path)
            print("Copied %s -> %s" % (src_name, dst_path))
        else:
            print("WARNING: Expected artifact not found: %s" % src_path)

    print("All build artifacts collected in: %s" % build_output_dir)


env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", generate_build_info)