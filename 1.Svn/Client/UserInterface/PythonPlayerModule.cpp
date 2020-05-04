//Find
	PyModule_AddIntConstant(poModule, "DS_SUB_HEADER_DO_REFINE",	DS_SUB_HEADER_DO_REFINE);

///Add
#if defined(TOOLTIP_GROUND_ITEM)
	PyModule_AddIntConstant(poModule, "TOOLTIP_LIMIT_RANGE", TooltipData::TOOLTIP_LIMIT_DIST);
#endif