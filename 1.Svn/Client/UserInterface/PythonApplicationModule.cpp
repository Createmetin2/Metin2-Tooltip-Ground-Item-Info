//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#ifdef TOOLTIP_GROUND_ITEM
	PyModule_AddIntConstant(poModule, "TOOLTIP_GROUND_ITEM",	1);
#else
	PyModule_AddIntConstant(poModule, "TOOLTIP_GROUND_ITEM",	0);
#endif