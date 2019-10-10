//Find
void CItemData::SetItemTableData(TItemTable * pItemTable)
{
	memcpy(&m_ItemTable, pItemTable, sizeof(TItemTable));
}

///Add
#if defined(TOOLTIP_GROUND_ITEM)
void CItemData::SetSocAttr(const std::vector<long>& socket, const std::vector<BYTE>& attrtypes, const std::vector<short>& attrvals)
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
#if defined(TOOLTIP_GROUND_ITEM)
	sockets.clear();
	attrtype.clear();
	attrval.clear();
#endif	