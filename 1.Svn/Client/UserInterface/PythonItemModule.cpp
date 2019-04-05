//Find
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
	std::vector<long> a;
	std::vector<BYTE> b;
	std::vector<short> c;

	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber ,a,b,c, x, y, z, bDrop);
#else
	CPythonItem::Instance().CreateItem(iVirtualID, iVirtualNumber, x, y, z, bDrop);
#endif