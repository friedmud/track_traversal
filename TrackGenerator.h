#ifndef TRACK_GENERATOR
#define TRACK_GENERATOR

// System Includes
#include <vector>

// Local Includes
#include "Track.h"

class TrackGenerator
{
public:
  TrackGenerator(unsigned int num_2d_tracks, double track_length, unsigned int num_z_tracks):
      _num_2d_tracks(num_2d_tracks),
      _track_length(track_length),
      _num_z_tracks(num_z_tracks),
      _2d_tracks(num_2d_tracks)
  {
    for (unsigned int i=0; i<num_2d_tracks; i++)
      _2d_tracks[i] = new Track(i);
  }

  ~TrackGenerator()
  {
    for (unsigned int i=0; i<_num_2d_tracks; i++)
      delete _2d_tracks[i];
  }

  unsigned int num2DTracks() { return _num_2d_tracks; }
  unsigned int numZTracks() { return _num_z_tracks; }

  const std::vector<Track *> & tracks2D() { return _2d_tracks; }

protected:
  unsigned int _num_2d_tracks;
  double _track_length;
  unsigned int _num_z_tracks;

  std::vector<Track *> _2d_tracks;
};

#endif
