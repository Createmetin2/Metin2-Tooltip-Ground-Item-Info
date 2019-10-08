//Find in: void CItem::EncodeInsertPacket(LPENTITY ent)
	pack.dwVID		= m_dwVID;
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	thecore_memcpy(pack.alSockets, m_alSockets, sizeof(pack.alSockets));
	thecore_memcpy(pack.aAttr, GetAttributes(), sizeof(pack.aAttr));
#endif