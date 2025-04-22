program MARIO;
const   fi='test9\MARIO.INP';
        fo='test9\MARIO.OUT';
        nmax = 1001;
type    BigNum = String;
var     A:array[1..nmax] of integer;
        F:array[0..nmax+1] of BigNum;
        N:integer;
        f1:text;
procedure doc;
var i:integer;
begin
    assign(f1,fi); reset(f1);
    Readln(f1,N);
    for i:=1 to N do read(f1,A[i]);
    close(f1);
end;
function Tong(X,Y:BigNum):BigNum;
var i,nho,T:longint;
    Z:bigNum;
Begin
    nho := 0;
    While length(X)<length(Y) do X := '0' + X;
    While length(X)>length(Y) do Y := '0' + Y;
    Z:= '';
    for i:=length(X) downto 1 do
    Begin
        T := ord(X[i]) + ord(Y[i]) - 96 + nho;
        Z := chr(T mod 10 + 48) + Z;
        nho := T div 10;
    end;
    if nho > 0 then Z := '1' + Z;
    Tong := Z;
end;
procedure xuly;
var i:longint;
begin
    F[0] :='1';
    if A[1] = 2 then F[1] := '0'
    else F[1] := '1';

    if A[2] = 2 then F[2] := '0'
    else if A[2] = 1 then F[2] := F[1]
         else Begin
                    F[2] := Tong(F[1],F[0]);
              end;

    if A[3] = 2 then F[3] := '0'
    else if A[3] = 1 then F[3] := F[2]
         else F[3] := Tong(Tong(F[0],F[1]),F[2]);

    for  i:=4 to N+1 do
    if A[i] = 2 then F[i] := '0'
    else if A[i] = 1 then F[i] := F[i-1]
         else if A[i-3] = 1 then F[i] := tong(F[i-1],F[i-2])
              else F[i] := Tong(Tong(F[i-1],F[i-2]),F[i-3])
end;
procedure ghi;
var i:longint;
begin
    assign(f1,fo); rewrite(f1);
    write(f1,F[N+1]);
    close(f1);
end;
BEGIN
    doc;
    xuly;
    ghi;
END.
