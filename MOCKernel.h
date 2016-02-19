#ifndef MOCKernel
#define MOCKernel

// Dummy class for splitting constructor
class split {};


class MOCKernel
{
public:
  MOCKernel() {}

  virtual void execute(double segment_length, unsigned int FSR_id);

protected:

};

#endif
