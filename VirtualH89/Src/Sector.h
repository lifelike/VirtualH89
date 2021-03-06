///
/// \name Sector.h
///
///
/// \date Jun 22, 2013
/// \author Mark Garlanger
///

#ifndef SECTOR_H_
#define SECTOR_H_

#include "h89Types.h"

class Sector
{
  private:
    BYTE  headNum_m;
    BYTE  trackNum_m;
    BYTE  sectorNum_m;
    bool  deletedDataAddressMark_m;
    bool  readError_m;
    bool  valid_m;
    BYTE* data_m;
    WORD  sectorLength_m;
    Sector();

  public:

    //
    Sector(BYTE  headNum,
           BYTE  trackNum,
           BYTE  sectorNum,
           WORD  sectorLength,
           BYTE* data);

    Sector(BYTE headNum,
           BYTE trackNum,
           BYTE sectorNum,
           WORD sectorLength,
           BYTE data = 0xe5);
    virtual ~Sector();

    void setDeletedDataAddressMark(bool val);
    void setReadError(bool val);

    bool getDeletedDataAddressMark();
    bool getReadError();

    BYTE getSectorNum();
    WORD getSectorLength();
    BYTE getHeadNum();
    BYTE getTrackNum();

    bool readData(WORD  pos,
                  BYTE& data);
    bool writeData(WORD pos,
                   BYTE data);

    void dump();
};

#endif // SECTOR_H_
