#include <imgcodecs.hpp>

extern "C"
struct TensorWrapper imread(const char *filename, int flags)
{
    return TensorWrapper(cv::imread(filename, flags));
}

extern "C"
struct TensorArrayPlusBool imreadmulti(const char *filename, int flags)
{
    TensorArrayPlusBool retval;
    std::vector<cv::Mat> result;
    retval.val = cv::imreadmulti(filename, result, flags);
    new (&retval.tensors) TensorArray(result);
    return retval;
}

extern "C"
bool imwrite(const char *filename, struct TensorWrapper img, struct TensorWrapper params)
{
    return cv::imwrite(filename, img.toMat(), params.toMat());
}

extern "C"
struct TensorWrapper imdecode(struct TensorWrapper buf, int flags)
{
    return TensorWrapper(cv::imdecode(buf.toMat(), flags));
}
