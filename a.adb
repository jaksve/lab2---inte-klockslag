with Text_IO;
procedure A is 
   use Text_IO,ascii;
   X,n,s,u:Integer;
   B:Character;
begin 
   N:=Integer'Value(Get_Line);
   U:=0;
   s:=0;
 
	  for I in 1..N loop
	     Get(B);
	     case b is 
		when'h'=>S:=S+1;
		when'v'=>S:=S-1;
		when'f'=>U:=U+1;
		when others=>U:=U-1;
	     end case;
	     X:=I;
	     exit when U=0 and S=0;
	     end loop;
   if U=0 and S=0 then 
      Put(Lf&"Tillbaka till utgångspunkten efter"&X'image&" steg.");  
   else Put(Lf&"Kom aldrig tillbaka!");
   end if;
end a;
