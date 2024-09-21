#include "GFX/ImageProcessing.hpp"


void ProcessImage(cv::Mat& image1, cv::Mat& image2, cv::Mat& result, ImageOperations which)
{
	switch (which)
	{
	case oAdd:
		Add(image1, image2, result);
		break;
	case oSubstract:
		Substract(image1, image2, result);
		break;
	case oMultiply:
		Multiply(image1, image2, result);
		break;
	case oNegative:
		Negative(image1, result);
		break;
	case oGammaCorrection:
		GammaCorrection(image1, result);
		break;
	case oLogTransform:
		LogTransform(image1, result);
		break;
	case oNeighbours:
		Neighbours(image1, result);
		break;
	default:
		break;
	}
}

void Add(cv::Mat& image1, cv::Mat& image2, cv::Mat& result)
{
	cv::add(image1, image2, result);
}

void Substract(cv::Mat& image1, cv::Mat& image2, cv::Mat& result)
{
	cv::subtract(image1, image2, result);
}

void Multiply(cv::Mat& image1, cv::Mat& image2, cv::Mat& result)
{
	cv::multiply(image1, image2, result);
}

void Negative(cv::Mat& imgae1, cv::Mat& result)
{
	cv::subtract(cv::Scalar::all(255), imgae1, result);
}

void GammaCorrection(cv::Mat& image1, cv::Mat& result)
{
	//lets see what to do later on 
}

void LogTransform(cv::Mat& image1, cv::Mat& result)
{
	//lets see what to do later on 
}

void Neighbours(cv::Mat& image1, cv::Mat& result)
{
	//lets see what to do later on 
}