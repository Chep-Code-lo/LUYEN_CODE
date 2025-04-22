const   fi='BANGSO.INP';
        fo='BANGSO.OUT';
        maxn=1000001;
var     f:text;
        n,kq,dem:int64;
        a,fl,fc,ds:array[1..maxn] of int64;
        luuc,luul:array[1..maxn] of integer;
procedure       nhap;
var     i:longint;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]) ;
        close(f);
        dem:=0;
        fillchar(luul,sizeof(luul),0);
        fillchar(luuc,sizeof(luuc),0);

end;
function        max2so(cl,j,x,y:int64):int64;
begin

        if x>y  then   max2so:=x
        else    begin
                        max2so:=y;
                        if cl=0 then luuc[j]:=1;
                        if cl=1 then luul[j]:=1;
                end;

end;
procedure       xuli;
var i,chanle:longint;
begin
      fl[1]:=a[1];
      fc[1]:=0;
      for i:=2 to n do
        begin
              fl[i]:=max2so(1,i,fl[i-1],fc[i-1]+a[i]);
              fc[i]:=max2so(0,i,fc[i-1],fl[i-1]-a[i]);
        end;
      if fl[n]>fc[n] then begin kq:=fl[n];chanle:=1;end
      else begin kq:=fc[n];chanle:=0;end;
      for i:=n downto 1 do
        begin
                if (chanle=1) and (luul[i]=1) then
                        begin
                                inc(dem);
                                ds[dem]:=i;
                                chanle:=0;
                                continue;
                        end;
                if (chanle=0) and (luuc[i]=1) then
                        begin
                              inc(dem);
                              ds[dem]:=i;
                              chanle:=1;
                        end;
        end;

end;
procedure       xuat;
var i:longint;
begin
        assign(f,fo);
        rewrite(f);
        writeln(f,kq);
        for i:=dem downto 1 do
                write(f,ds[i],' ');
        close(f)
end;

BEGIN
        nhap;
        xuli;
        xuat;
END.
