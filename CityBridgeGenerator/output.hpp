#pragma once
inline void OptOut(int i)
{
	if(Data[i].to)
	{
		if(Data[i].opt==1)printf("union(){");
		if(Data[i].opt==2)printf("difference(){");
		if(Data[i].opt==3)printf("intersection(){");
	}
	Data[i].ElementInfoGenerate();
	if(Data[i].to)OptOut(Data[i].to);
	if(Data[i].to)printf("}");
}
inline void Output()
{
	for(int i=1;i<=ElementCnt;i++)
	{
		if(vis[i])continue;
		OptOut(i);//µÝ¹éµ÷ÓÃ
		printf("\n"); 
	}
}
