///
/// \name H47Drive.h
///
///
/// \date Jul 27, 2013
/// \author Mark Garlanger
///

#ifndef H47DISK_H_
#define H47DISK_H_

#include "DiskDrive.h"

#include "h89Types.h"
/// \cond
#include <memory>
/// \endcond

class H47Drive: public DiskDrive
{
  public:
    H47Drive();
    virtual ~H47Drive() override;

    virtual void getControlInfo(unsigned long pos,
                                bool&         hole,
                                bool&         trackZero,
                                bool&         writeProtect) override;

    virtual void selectSide(BYTE side) override;
    virtual void step(bool direction) override;

    virtual BYTE readData(unsigned long pos) override;
    virtual void writeData(unsigned long pos,
                           BYTE          data) override;
    virtual BYTE readSectorData(BYTE          sector,
                                unsigned long pos) override;
    virtual void insertDisk(std::shared_ptr<FloppyDisk> disk) override;

  private:
    static const unsigned int maxTracks_c          = 77;
    static const unsigned int maxSectorsPerTrack_c = 26;
    static const unsigned int maxBytesPerSector_c  = 256;

    static const unsigned int sectorsPerTrack_c    = 8;


    unsigned int              tracks_m;
    unsigned int              sectors_m;
    unsigned int              bytes_m;

    unsigned int              track_m;
    unsigned int              sector_m;
    unsigned int              byte_m;

    BYTE                      data_m[maxTracks_c][maxSectorsPerTrack_c][maxBytesPerSector_c];

};

#endif // H47DRIVE_H_
