Import("env")
my_flags = env.ParseFlags(env["BUILD_FLAGS"])
defines = dict()
for b in my_flags.get("CPPDEFINES"):
    if isinstance(b, list):
        defines[b[0]] = b[1]
    else:
        defines[b] = b

stepper_suffix = str(defines.get("STEPPER_SUFFIX", "")).strip('"')
hemisphere = str(defines.get("c_DIRECTION", "")).strip('"')

if stepper_suffix == "09deg":
    stepper_suffix = "0.9deg"
elif stepper_suffix == "18deg":
    stepper_suffix = "1.8deg"
if hemisphere == "1":
    hemisphere = "north"
else:
    hemisphere = "south"

if defines.get("DEBUG") == "1":
    if stepper_suffix:
        env.Replace(
            PROGNAME="%s_%s_%s_%s"
            % (
                str(defines.get("BINARY_NAME")),
                str(defines.get("FIRMWARE_VERSION")),
                stepper_suffix,
                "debug",
            )
        )
    else:
        env.Replace(
            PROGNAME="%s_%s_%s"
            % (str(defines.get("BINARY_NAME")), str(defines.get("FIRMWARE_VERSION")), "debug")
        )
else:
    if stepper_suffix:
        env.Replace(
            PROGNAME="%s_v%s_%s_%s"
            % (defines.get("BINARY_NAME"), defines.get("FIRMWARE_VERSION"), stepper_suffix, hemisphere)
        )
    else:
        env.Replace(
            PROGNAME="%s_v%s_%s" % (defines.get("BINARY_NAME"), defines.get("FIRMWARE_VERSION"), hemisphere)
        )