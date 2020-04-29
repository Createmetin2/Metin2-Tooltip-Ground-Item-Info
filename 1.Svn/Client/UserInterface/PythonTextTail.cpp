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

//Find
	m_ChatTailMap.clear();
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	ItemTooltipMap.clear();
#endif
