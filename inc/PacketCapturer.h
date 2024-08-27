#pragma once

#include <IPv4Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>

class PacketCapturer
{
public:

    PacketCapturer(const std::string& command, const std::string& filename);

    void capturePackets();

private:
    std::string m_command;
    std::string m_filename;
};