#ifndef __I_WATEK__H__
#define __I_WATEK__H__

#include <thread>
#include <mutex>

class IWatek
{
public:
    virtual ~IWatek();
    virtual void Start() = 0;
    virtual void Stop();
    virtual void GlownaPetla() = 0;

protected:
    bool m_aktywny = true;
    std::thread m_watek;
    std::mutex m_bariera;
};

#endif
