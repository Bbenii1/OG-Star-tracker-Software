#ifndef WEB_VALIDATION_H
#define WEB_VALIDATION_H

#include "error.h"
#include "intervalometer.h"
#include <WebServer.h>

// Validation helper functions
bool validateCaptureMode(int modeInt, ErrorMessage& error);
bool validateExposureTime(int exposureTime, ErrorMessage& error);
bool validateExposures(int exposures, ErrorMessage& error);
bool validatePreDelay(int preDelay, ErrorMessage& error);
bool validateDelayTime(int delayTime, ErrorMessage& error);
bool validateFrames(int frames, ErrorMessage& error);
bool validatePanAngle(float panAngle, ErrorMessage& error);
bool validatePanDirection(int panDirection, ErrorMessage& error);
bool validateEnableTracking(int enableTracking, ErrorMessage& error);
bool validateDitherChoice(int dither, ErrorMessage& error);
bool validateDitherFrequency(int ditherFrequency, ErrorMessage& error);
bool validateFocalLength(int focalLength, ErrorMessage& error);
bool validatePixelSize(float pixelSize, ErrorMessage& error);
bool validateSlewSpeed(int& slewSpeed);

#endif // WEB_VALIDATION_H

