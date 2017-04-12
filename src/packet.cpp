#include "mcstatus/packet.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include <boost/algorithm/string.hpp>

namespace
{

unsigned char convert(const std::string& s)
{
    unsigned char x;
    sscanf(s.c_str(), "%hhx", &x);
    return x;
}

} // namespace 

namespace mc
{

packet::packet()
{
}

packet::~packet()
{
    
}

void packet::setPacket(packet_t pt)
{
    packets = pt;
}

packet_t packet::getPacket() const
{
    return packets;
}

packet packet::from_string(const std::string& packets)
{
    //assert(!(packets.size() >= 1));

    packet_t buffer;
    
    std::vector<std::string> packets_split;
    boost::split(packets_split, packets, boost::is_any_of(" "));

    //packets_split.insert(packets_split.begin(), packets.substr(0, 2) );

    for (auto&& x : packets_split)
    {
        buffer.push_back(convert(x));
    }
    
    packet packet_new;
    packet_new.setPacket(buffer);

    return packet_new;
}

}
