#include "web_validation.h"
#include "config.h"
#include "error.h"

bool validateCaptureMode(int modeInt, ErrorMessage& error)
{
    if (modeInt < 0 || modeInt >= Intervalometer::Mode::MAX_MODES)
    {
        error = ERR_MSG_INVALID_CAPTURE_MODE;
        return false;
    }
    return true;
}

bool validateExposureTime(int exposureTime, ErrorMessage& error)
{
    if (exposureTime <= 0)
    {
        error = ERR_MSG_INVALID_EXPOSURE_LENGTH;
        return false;
    }
    return true;
}

bool validateExposures(int exposures, ErrorMessage& error)
{
    if (exposures <= 0)
    {
        error = ERR_MSG_INVALID_EXPOSURE_AMOUNT;
        return false;
    }
    return true;
}

bool validatePreDelay(int preDelay, ErrorMessage& error)
{
    if (preDelay < 0)
    {
        error = ERR_MSG_INVALID_PREDELAY_TIME;
        return false;
    }
    return true;
}

bool validateDelayTime(int delayTime, ErrorMessage& error)
{
    if (delayTime < 0)
    {
        error = ERR_MSG_INVALID_DELAY_TIME;
        return false;
    }
    return true;
}

bool validateFrames(int frames, ErrorMessage& error)
{
    if (frames <= 0)
    {
        error = ERR_MSG_INVALID_FRAME_AMOUNT;
        return false;
    }
    return true;
}

bool validatePanAngle(float panAngle, ErrorMessage& error)
{
    if (panAngle < 0.0)
    {
        error = ERR_MSG_INVALID_PAN_ANGLE;
        return false;
    }
    return true;
}

bool validatePanDirection(int panDirection, ErrorMessage& error)
{
    if (panDirection < 0 || panDirection > 1)
    {
        error = ERR_MSG_INVALID_PAN_DIRECTION;
        return false;
    }
    return true;
}

bool validateEnableTracking(int enableTracking, ErrorMessage& error)
{
    if (enableTracking < 0 || enableTracking > 1)
    {
        error = ERR_MSG_INVALID_ENABLE_TRACKING_VALUE;
        return false;
    }
    return true;
}

bool validateDitherChoice(int dither, ErrorMessage& error)
{
    if (dither < 0 || dither > 1)
    {
        error = ERR_MSG_INVALID_DITHER_CHOICE;
        return false;
    }
    return true;
}

bool validateDitherFrequency(int ditherFrequency, ErrorMessage& error)
{
    if (ditherFrequency <= 0)
    {
        error = ERR_MSG_INVALID_DITHER_FREQUENCY;
        return false;
    }
    return true;
}

bool validateFocalLength(int focalLength, ErrorMessage& error)
{
    if (focalLength <= 0)
    {
        error = ERR_MSG_INVALID_FOCAL_LENGTH;
        return false;
    }
    return true;
}

bool validatePixelSize(float pixelSize, ErrorMessage& error)
{
    if (pixelSize <= 0.0)
    {
        error = ERR_MSG_INVALID_PIXEL_SIZE;
        return false;
    }
    return true;
}

bool validateSlewSpeed(int& slewSpeed)
{
    // Limit custom slew speed to 2-400
    if (slewSpeed > MAX_CUSTOM_SLEW_RATE)
    {
        slewSpeed = MAX_CUSTOM_SLEW_RATE;
    }
    else if (slewSpeed < MIN_CUSTOM_SLEW_RATE)
    {
        slewSpeed = MIN_CUSTOM_SLEW_RATE;
    }
    return true;
}

