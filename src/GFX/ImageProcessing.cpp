#include "GFX/ImageProcessing.hpp"


void ProcessImage(cv::Mat& image1, cv::Mat& image2, cv::Mat& result, ImageOperations which)
{
	cv::Mat resized;
	bool resized1= false;
	bool resized2= false;
	if (image1.empty())
	{
		return;
	}
	else if (image2.empty() == false )
	{
		//if the size is not the same 
			// then we see which is smaller and resize it
		if (image1.size() != image2.size())
		{
			if (image1.size > image2.size)
			{
				resized2 = true;
				cv::resize(image2, resized, image1.size());
			}
			else
			{
				resized1 = true;
				cv::resize(image1, resized, image2.size());
			}
		}
	}
	
	ActualOperation(resized1 ? resized : image1, resized2 ? resized: image2, result,which);
}

void ActualOperation(cv::Mat image1, cv::Mat image2, cv::Mat& result, ImageOperations which)
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