///Add
#if defined(TOOLTIP_GROUND_ITEM)
void CPythonTextTail::RegisterItemToolTipInfo(const DWORD& id, const std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>>& TooltipData)
{
	ItemTooltipMap[id] = TooltipData;
}
bool CPythonTextTail::GetSocketsAndAttr(const DWORD& id, std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>>& TooltipData)
{
	if (ItemTooltipMap.find(id) == ItemTooltipMap.end())
		return false;

	TooltipData = ItemTooltipMap.at(id);
	return true;
}
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
