from subprocess import *
import subprocess
import select
import sys

# Инициализируем имя переменной и номер итерации
valid_value = 38531
user_value = 0
step = 0
success = False
user_script = 'b main;r;watch crc;c;c 4'
# Разбираем параметры командной строки
if len(sys.argv) > 1:
	valid_value = int(sys.argv[1])
if len(sys.argv) > 2:
	user_script = sys.argv[2]

script_lines = user_script.split(';')
# print(script_lines)
	
# Запускаем программу crc16 под GDB
p = Popen(['gdb', 'crc16'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
op = select.poll()
op.register(p.stdout, select.POLLIN)


# Отправка команды GDB
def send_command(p, c):
	p.stdin.write((c + '\n').encode())
	p.stdin.flush()

# Отправка команды и ожидание завершения выполнения программы под отладчиком
def send_command_readout(p, c):
	send_command(p, c)
	global success
	global user_value
	global step
	while op.poll(1):
		line = p.stdout.readline().decode()
		#print(line, end='')
		if 'process' in line and 'exited' in line:
			return False
		line = line.strip('\n')
		if line.startswith('New value'):
			if step == 1:
				success = True
				user_value = int(line[12:])
			step += 1			
	return True
	
# Выполнение пользовательского скрипта
for script_line in script_lines:
	send_command(p, script_line)

# Выполнение до конца программы
while True:
	if not send_command_readout(p, 'c'):
		break

# Выход из отладчика
send_command(p, 'quit')

p.communicate()
p.wait()

# Код завершения: 0 - успешно, 1 - неверное значение, 2 - не получен результат
exit_code = 0
if not success:
	exit_code = 2
elif user_value != valid_value:
	exit_code = 1

print(user_value)
print('exit_code', exit_code)
sys.exit(exit_code)

