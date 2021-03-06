#ifndef TRACK
#define TRACK

#include <stdlib.h>

class Track
{
public:
  Track(unsigned int id):
      _id(id),
      _num_segments(((double)rand()/(double)RAND_MAX) * 100) // Random number of segments between 0 and 100
  {}

  unsigned int id() { return _id; }
  unsigned int numSegments() { return _num_segments; }

protected:
  unsigned int _id;
  unsigned int _seed;
  unsigned int _num_segments;
};

#endif
