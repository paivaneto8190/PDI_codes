#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char** argv){
  cv::Mat image;
  int pixel_x1, pixel_y1, pixel_x2, pixel_y2, height, width;

  std::cin >> pixel_x1 >> pixel_y1 >> pixel_x2 >> pixel_y2;

  image= cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
  if(!image.data)
    std::cout << "nao abriu " << argv[1] << std::endl;

  cv::namedWindow("Janela", cv::WINDOW_AUTOSIZE);
  
  cv::imshow("Imagem original", image);  
  cv::waitKey();
  
  for(int i=pixel_x1;i<pixel_x2;i++){
    for(int j=pixel_y1;j<pixel_y2;j++){
      image.at<uchar>(i,j) = 255 - image.at<uchar>(i,j);
    }
  }

  cv::imshow("Imagem negativa", image);  
  cv::waitKey();
  return 0;
}