#include "TrackGenerator.h"

#include <iostream>

int main()
{
  // Because OSX is stupid
  for (unsigned int i=0; i<3; i++)
    rand();

  TrackGenerator track_generator(5, 10, 1);

  for (auto & track : track_generator.tracks2D())
  {
    std::cout<<track->id()<<": "<<track->numSegments()<<std::endl;
  }

  return 0;
}
