//Find in : void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)
	CPythonTextTail& rkTextTail=CPythonTextTail::Instance();
	rkTextTail.RegisterItemTextTail(
		dwVirtualID,
		pItemData->GetName(),
		&pGroundItemInstance->ThingInstance
	);
	
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	rkTextTail.RegisterItemToolTipInfo(dwVirtualID, tooltiptuple);
#endif

//Find
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop)

///Change
void CPythonItem::CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber,
#if defined(TOOLTIP_GROUND_ITEM)
const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple,
#endif
float x, float y, float z, bool bDrop)
