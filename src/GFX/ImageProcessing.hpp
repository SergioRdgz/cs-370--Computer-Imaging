#pragma once

#include "opencv2/opencv.hpp"
#include <opencv2/core/utils/logger.hpp>

enum ImageOperations
{
	oNone,
	oAdd,
	oSubstract,
	oMultiply,
	oNegative,
	oGammaCorrection,
	oLogTransform,
	oNeighbours
};

void ProcessImage(cv::Mat& image1, cv::Mat& image2, cv::Mat& result, ImageOperations which);

//one operation per each image operation

void Add(cv::Mat& image1, cv::Mat& image2, cv::Mat& result);

void Substract(cv::Mat& image1, cv::Mat& image2, cv::Mat& result);

void Multiply(cv::Mat& image1, cv::Mat& image2, cv::Mat& result);

void Negative(cv::Mat& image1, cv::Mat& result);

void GammaCorrection(cv::Mat& image1, cv::Mat& result);

void LogTransform(cv::Mat& image1, cv::Mat& result);

void Neighbours(cv::Mat& image1, cv::Mat& result);
