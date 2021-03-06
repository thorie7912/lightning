#ifndef LIGHTNING_WIRE_PEER_WIRE_H
#define LIGHTNING_WIRE_PEER_WIRE_H
#include "config.h"
#include <stdbool.h>
#include <wire/gen_peer_wire.h>

/* BOLT #1:
 *
 * A node MUST ignore a received message of unknown type, if that type is odd.
 *
 * A node MUST fail the channels if it receives a message of unknown type, if
 * that type is even.
 */

/* Return true if it's an unknown message.  cursor is a tal ptr. */
bool is_unknown_msg(const u8 *cursor);
/* Return true if it's an unknown ODD message.  cursor is a tal ptr. */
bool is_unknown_msg_discardable(const u8 *cursor);
/* Return true if it's a gossip message. */
bool is_gossip_msg(const u8 *cursor);

/* BOLT #2:
 *
 * Only the least-significant bit of `channel_flags` is currently
 * defined: `announce_channel`.  This indicates whether the initiator
 * of the funding flow wishes to advertise this channel publicly to
 * the network as detailed within [BOLT #7]
 */
#define CHANNEL_FLAGS_ANNOUNCE_CHANNEL 1

/* BOLT #7:
 *
 * Upon establishing a connection, the two endpoints negotiate whether
 * to perform an initial sync by setting the `initial_routing_sync`
 * flags in the `init` message. The endpoint SHOULD set the
 * `initial_routing_sync` flag if it requires a full copy of the other
 * endpoint's routing state. Upon receiving an `init` message with the
 * `initial_routing_sync` flag set the node sends `channel_announcement`s,
 * `channel_update`s and `node_announcement`s for all known channels and
 * nodes as if they were just received.
 */
#define LOCALFEATURES_INITIAL_ROUTING_SYNC 0x08

/* Compare two short_channel_ids and return true if they are the equal */
bool short_channel_id_eq(const struct short_channel_id *a,
			 const struct short_channel_id *b);
#endif /* LIGHTNING_WIRE_PEER_WIRE_H */
