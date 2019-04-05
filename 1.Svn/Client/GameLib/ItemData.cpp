//Find
void CItemData::SetItemTableData(TItemTable * pItemTable)
{
	memcpy(&m_ItemTable, pItemTable, sizeof(TItemTable));
}

///Add
#ifdef TOOLTIP_GROUND_ITEM
void CItemData::SetSocAttr(std::vector<long> socket, std::vector<BYTE> attrtypes, std::vector<short> attrvals)
{
	sockets.clear();
	attrtype.clear();
	attrval.clear();

	sockets = socket;
	attrtype = attrtypes;
	attrval = attrvals;
}
#endif

//Find
	memset(&m_ItemTable, 0, sizeof(m_ItemTable));
	
///Add
#ifdef TOOLTIP_GROUND_ITEM
	memset(&sockets, 0, sizeof(sockets));
	memset(&attrtype, 0, sizeof(attrtype));
	memset(&attrval, 0, sizeof(attrval));
#endif	