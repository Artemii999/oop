rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
echo "test0_1"
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
echo "test0_2"
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� (���� ���, ��������� ����������� � �����) ��������� ������� ��� ��������
echo "test0_3"
%PROGRAM% test_data\input.txt line >nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� �����������, �� ��� ����������� ��������� ���� (�� ���) ������� ��������� ��� ��������
echo "test0_4"
%PROGRAM% notExistFile.txt Hello >nul
if NOT ERRORLEVEL 1 goto err

rem ����� ����� �������� ��������������� � ������� ��������� � ������

rem ��������� ��� ���������� ���������� � ������������ ����� ��������� ���� ���� � ������� ������ � ������������
echo "test1"
%PROGRAM% test_data\input.txt line >"%temp%\output.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output.txt" "test_data\etalon-answer-for-input.txt" >nul
if ERRORLEVEL 1 goto err

rem ��� ���������� ���������� � ��� ����� �� ������� ������ ���������� � ����� ������ (���������� ���������)
echo "test2"
%PROGRAM% test_data\input2.txt line >"%temp%\output2.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output2.txt" "test_data\etalon-answer-for-input2.txt" >nul
if not ERRORLEVEL 1 goto err

rem ���� �� ���������� ��������� ������ ����� � �������� �����
echo "test3"
%PROGRAM% test_data\input4.txt line >"%temp%\output4.txt"
if ERRORLEVEL 1 goto err
fc.exe "%temp%\output4.txt" "test_data\etalon-answer-for-input4.txt" >nul
if ERRORLEVEL 1 goto err

rem ���� � ������ �� ������� ����� ���������, �� ������� `Text not found`
echo "test4"
%PROGRAM% test_data\input5.txt line >"%temp%\output5.txt"
if not ERRORLEVEL 1 goto err
fc.exe "%temp%\output5.txt" "test_data\etalon-answer-for-input5.txt" >nul
if ERRORLEVEL 1 goto err


echo Testing pass!
exit 0

:err
echo Program testing failed
exit 1