#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>

#include <string>

#define DO_QUOTE(X) #X
#define QUOTE(X) DO_QUOTE(X)

namespace {
    const std::string SERVR_ROOT   = QUOTE(WEB_ROOT);
    const std::string PUBLIC_ROOT  = WEB_ROOT + "/public/";
    const std::string WEB_TEMP     = WEB_ROOT + "/temp/";
          std::string OPENCV_ERROR = "";
    const char       *ERRORS[]     =
    {
	"Invalid error code",
	"Face not recognized",
	"OpenCV exception: ",
	"Image size incorrect"
    };
}

const char *pluggr_get_error(int code)
{
    if (code >= 0 || code <= sizeof(ERRORS) / sizeof(ERRORS[0]))
	return ERRORS[0];

    if (-code == -2)
	return (ERRORS[-code] + OPENCV_ERROR).c_str();

    return ERRORS[-code];
}

int pluggr_recognize(const char *face_file, const char *recognizer_path)
{
    cv::Mat image = cv::imread((WEB_TEMP + face_file).c_str(), CV_LOAD_IMAGE_GRAYSCALE);
    if (image.size() != cv::Size(256, 256))
	return -3;

    static const double DISTANCE_TRESHOLD = 2000.0;
    cv::Ptr<cv::FaceRecognizer> recognizer;
    recognizer = cv::createFisherFaceRecognizer(0, DISTANCE_TRESHOLD);
    recognizer->load((PUBLIC_ROOT + recognizer_path).c_str());
    
    try
    {
	return recognizer->predict(image);
    }
    catch(const cv::Exception &e)
    {
	OPENCV_ERROR = e.what();
	return -2;
    }
}
