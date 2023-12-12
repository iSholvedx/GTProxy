#pragma once
#include <vector>
#include <enet/enet.h>

namespace player {
class Player  {
public:
    explicit Player(ENetPeer* peer);
    ~Player() = default;

    [[nodiscard]] bool is_connected() const { return peer_->state == ENET_PEER_STATE_CONNECTED; }
    [[nodiscard]] bool is_disconnected() const { return peer_->state == ENET_PEER_STATE_DISCONNECTED; }

    void disconnect() const { enet_peer_disconnect(peer_, 0); }
    void disconnect_now() const { enet_peer_disconnect_now(peer_, 0); }

    bool send_packet(const std::vector<std::byte>& data, int channel = 0) const;

private:
    ENetPeer* peer_;
};
}