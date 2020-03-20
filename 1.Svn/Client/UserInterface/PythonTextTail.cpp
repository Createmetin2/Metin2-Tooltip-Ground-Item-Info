///Add
#if defined(TOOLTIP_GROUND_ITEM)
void CPythonTextTail::RegisterItemToolTipInfo(const DWORD& id, const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple)
{
	ItemTooltipMap[id] = tooltiptuple;
}
bool CPythonTextTail::GetSocketsAndAttr(const DWORD& id, std::tuple<std::vector<long>, std::vector<TPlayerItemAttribute>>& ItemTuple)
{
	if (ItemTooltipMap.find(id) == ItemTooltipMap.end())
		return false;

	ItemTuple = ItemTooltipMap.at(id);
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
