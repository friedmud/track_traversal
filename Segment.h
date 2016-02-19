#ifndef SEGMENT_H
#define SEGMENT_H

class Segment
{
public:
  Segment(double length, double Sig_t):
      _length(length),
      _Sig_t(Sig_t)
  {}

  double length() { return _length; }
  double SigT() { return _Sig_t; }

protected:
  double _length;
  double _Sig_t;
};

#endif
