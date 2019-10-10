//Find in : typedef struct packet_ground_add_item
	DWORD       dwVnum;
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	long		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
	DWORD ItemID;
#endif	