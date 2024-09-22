#include "GFX/ImageProcessing.hpp"

#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>



void ProcessImage(cv::Mat& image1, cv::Mat& image2, cv::Mat& result, ImageOperations which, float c, float y)
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
	
	ActualOperation(resized1 ? resized : image1, resized2 ? resized: image2, result,which,c,y);
}

void ActualOperation(cv::Mat image1, cv::Mat image2, cv::Mat& result, ImageOperations which, float c, float y)
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
		GammaCorrection(image1, result,c,y);
		break;
	case oLogTransform:
		LogTransform(image1, result,c);
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

void GammaCorrection(cv::Mat& image1, cv::Mat& result,float c,float y)
{
	try
	{
		//conver to a float value
		image1.convertTo(image1, CV_64F, 1.0 / 255.0);
		cv::pow(image1, (double)(1.0/y), result);

		//convert back to a grey scale image
		result.convertTo(result, CV_8U, 255.0);
		result *= c; 
	}
	catch (cv::Exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void LogTransform(cv::Mat& image1, cv::Mat& result, float c)
{
	try
	{
		image1.convertTo(image1, CV_64F, 1.0 / 255.0);
		cv::log(cv::Scalar::all(1)+image1, result);
		result.convertTo(result, CV_8U, 255.0);
		result *= c;
	}
	catch (cv::Exception& e)
	{
	 std::cout << e.what() << std::endl;
	}
}

void Neighbours(cv::Mat& image1, cv::Mat& result)
{
	//lets see what to do later on 
}