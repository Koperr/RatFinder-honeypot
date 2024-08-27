#include <iostream>
#include <map>
#include <fstream>

#include <IPv4Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>

#include "PacketCapturer.h"


int main(int argc, char* argv[])
{
    std::string content = "";
    std::fstream logs;


    // setting tcdump command
    std::string command = "sudo tcpdump -i en0 -w ../../../dupa.pcap -G 3 -W 1";

    // executing tcdump command
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Capturing completed succesfuly" << std::endl;
    } else {
        std::cerr << "Error occured while captureing" << std::endl;
    }


    // open a pcap file for reading
    pcpp::PcapFileReaderDevice reader("../../../dupa.pcap");
    if (!reader.open())
    {
        std::cerr << "Error opening the pcap file" << std::endl;
        return 1;
    }

    std::map<std::string, std::string> ipMap;

    pcpp::RawPacket rawPacket;
    while (reader.getNextPacket(rawPacket)) {
        // Tworzenie obiektu pakietu na podstawie surowego pakietu
        pcpp::Packet parsedPacket(&rawPacket);

        // Pobranie warstwy IPv4, jeśli jest dostępna
        pcpp::IPv4Layer* ipv4Layer = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();
        if (ipv4Layer != nullptr) {
            std::cout << "Source IP: " << ipv4Layer->getSrcIPAddress().toString() << std::endl;
            std::cout << "Destination IP: " << ipv4Layer->getDstIPAddress().toString() << std::endl;

            content += "Source IP: " + ipv4Layer->getSrcIPAddress().toString() + "\n";
            content += "Destination IP: " + ipv4Layer->getDstIPAddress().toString() + "\n";
        }
    }
    // close the file
    reader.close();


    std::cout << "str size = " << content.size() << std::endl;

    logs.open("../../../Logs.txt", std::ios::out);
    logs << content;
    logs.close();

    return 0;
}