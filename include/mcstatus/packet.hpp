#ifndef JINGJING_PACKET_HPP
#define JINGJING_PACKET_HPP

#include <string>
#include <vector>

namespace mc
{

typedef std::vector<unsigned char> packet_t;

class packet
{
public:
    packet(const std::string& packets);
    packet();
    ~packet();

public:
    void setPacket(packet_t pt);
    packet_t getPacket() const;
    
    static packet from_string(const std::string& packets);
protected:
    packet_t packets;
}; // class packet


} // namespace mc

#endif // !JINGJING_PACKET_HPP
