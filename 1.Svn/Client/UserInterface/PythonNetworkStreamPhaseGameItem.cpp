//Find
	__GlobalPositionToLocalPosition(packet_item_ground_add.lX, packet_item_ground_add.lY);
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	std::vector<long> sockets(packet_item_ground_add.alSockets, packet_item_ground_add.alSockets + ITEM_SOCKET_SLOT_MAX_NUM);
	std::vector<TPlayerItemAttribute> attr(packet_item_ground_add.aAttr, packet_item_ground_add.aAttr + ITEM_ATTRIBUTE_SLOT_MAX_NUM);
#endif

//Find
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID, 
									   packet_item_ground_add.dwVnum,
									   packet_item_ground_add.lX,
									   packet_item_ground_add.lY,
									   packet_item_ground_add.lZ);
	
///Change
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID,packet_item_ground_add.dwVnum,
									#if defined(TOOLTIP_GROUND_ITEM)
										std::make_tuple(sockets, attr),
									#endif
										packet_item_ground_add.lX,packet_item_ground_add.lY,packet_item_ground_add.lZ);