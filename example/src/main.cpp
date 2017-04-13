#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <mcstatus/mcstatus.hpp>

void usage()
{
    std::cout <<
        "Usage: ./mcstatus --host <host> --port <port>" << std::endl <<
        "Example ./mcstatus -h 127.0.0.1 -p 25565" <<
    std::endl;
    exit(1);
}

int main(int argc, char** argv)
{
    if (argc == 1) usage();

    std::string hostname;
    short port;

    int opt_idx = 1;
    for (; opt_idx < argc; opt_idx++)
    {
        if (!*argv[opt_idx] =='-')
            break;

        if (!strcmp(argv[opt_idx], "--host") ||
            !strcmp(argv[opt_idx], "-h"))
        {
            ++opt_idx;
            hostname = argv[opt_idx];
        }
        else if (
            !strcmp(argv[opt_idx], "--port")||
            !strcmp(argv[opt_idx], "-p"))
        {
            ++opt_idx;
            port = static_cast<short> (std::atoi(argv[opt_idx]));
        }
        else
        {
            fprintf(stderr, "Unknown commandline flag: %s\n", argv[opt_idx]);
            usage();
        }
    }

    if (argc - opt_idx != 0) return 1;

    mc::status motd(hostname, port);
    mc::motd_t m = motd.getMotd();
    std::cout << "description: " << m.description << std::endl;
    std::cout << "players: " << m.player_online << "/" << m.player_max << std::endl;
    
    return 0;
}
