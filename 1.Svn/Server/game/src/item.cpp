//Find in: void CItem::EncodeInsertPacket(LPENTITY ent)
	pack.dwVID		= m_dwVID;
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	thecore_memcpy(pack.alSockets, GetSockets(), sizeof(pack.alSockets));
	thecore_memcpy(pack.aAttr, GetAttributes(), sizeof(pack.aAttr));
#endif
