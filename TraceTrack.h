#ifndef TRACE_TRACK
#define TRACE_TRACK

/**
 * Iterates over tracks, calling the PiecesKernel on each piece
 */
class TraceTrack
{
public:
  TraceTrack(const TrackGenerator & track_generator, PiecesKernel * pieces_kernel)
      :_track_generator(track_generator),
       _pieces_kernel(pieces_kernel)
    {}

protected:
  const TrackGenerator & track_generator
  PiecesKernel * pieces_kernel
};

#endif
