//Find
void CPythonTextTail::RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner)

///Change
void CPythonTextTail::RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner
#if defined(TOOLTIP_GROUND_ITEM)
,const long* socket, const TPlayerItemAttribute* attr
)
#endif

//Find
	m_ItemTextTailMap.insert(TTextTailMap::value_type(VirtualID, pTextTail));
	
///Add(endif)
#if defined(TOOLTIP_GROUND_ITEM)
	ItemTooltipMap.emplace(VirtualID, std::make_shared<TooltipData>(socket, attr));
#endif

//Find
	m_ItemTextTailMap.erase(itor);
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	if (ItemTooltipMap.find(VirtualID) != ItemTooltipMap.end())
		ItemTooltipMap.erase(VirtualID);
#endif

//Find in : void CPythonTextTail::SetItemTextTailOwner(DWORD dwVID, const char * c_szName)
	if (strlen(c_szName) > 0)
	{
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		const auto it = ItemTooltipMap.find(dwVID);
		if (ItemTooltipMap.end() != it)
			it->second->SetOwner(c_szName);
#endif	

//Find
	m_ChatTailMap.clear();
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	ItemTooltipMap.clear();
#endif
