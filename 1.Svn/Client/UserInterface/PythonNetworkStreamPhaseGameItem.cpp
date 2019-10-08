//Find
	__GlobalPositionToLocalPosition(packet_item_ground_add.lX, packet_item_ground_add.lY);
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	std::vector<long> sockets(packet_item_ground_add.alSockets, packet_item_ground_add.alSockets + ITEM_SOCKET_SLOT_MAX_NUM);
	std::vector<BYTE> attrtype;
	std::vector<short> attrvals;
	for (auto i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; i++) {
		attrtype.emplace_back(packet_item_ground_add.aAttr[i].bType);
		attrvals.emplace_back(packet_item_ground_add.aAttr[i].sValue);
	}
#endif

//Find
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID, 
									   packet_item_ground_add.dwVnum,
									   packet_item_ground_add.lX,
									   packet_item_ground_add.lY,
									   packet_item_ground_add.lZ);
	
///Change
	CPythonItem::Instance().CreateItem(packet_item_ground_add.dwVID,packet_item_ground_add.dwVnum,
									#ifdef TOOLTIP_GROUND_ITEM
										sockets,
										attrtype,
										attrvals,
									#endif
										packet_item_ground_add.lX,packet_item_ground_add.lY,packet_item_ground_add.lZ);