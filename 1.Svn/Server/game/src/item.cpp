//Find in: void CItem::EncodeInsertPacket(LPENTITY ent)
	pack.dwVID		= m_dwVID;
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	for (int i = 0; i < ITEM_SOCKET_MAX_NUM; ++i)
		pack.alSockets[i] = m_alSockets[i];
	thecore_memcpy(pack.aAttr, GetAttributes(), sizeof(pack.aAttr));
#endif