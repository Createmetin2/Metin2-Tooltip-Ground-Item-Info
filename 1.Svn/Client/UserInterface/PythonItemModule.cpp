//Find
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
	
///Change
#if defined(TOOLTIP_GROUND_ITEM)
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, nullptr, nullptr, x, y, z, bDrop);
#else
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
#endif