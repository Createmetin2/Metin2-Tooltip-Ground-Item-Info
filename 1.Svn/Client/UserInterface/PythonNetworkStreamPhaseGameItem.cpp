//Find
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID, 
									   packet_item_ground_add.dwVnum,
									   packet_item_ground_add.lX,
									   packet_item_ground_add.lY,
									   packet_item_ground_add.lZ);
	
///Change
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID, packet_item_ground_add.dwVnum,
#if defined(TOOLTIP_GROUND_ITEM)
		packet_item_ground_add.alSockets, packet_item_ground_add.aAttr,
#endif
		packet_item_ground_add.lX, packet_item_ground_add.lY, packet_item_ground_add.lZ);