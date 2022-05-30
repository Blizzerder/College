#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

#include "FindPathBFS.h"
using namespace std;

int dir[4][2]={ {0,1},{0,-1},{1,0},{-1,0}};
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define HEAD 0

int speed = 0;
void gotoxy(int x,int y)//����ƶ�����
{
	COORD c;
	c.X=x; c.Y=y; //c��ʾΪҪ�������λ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); //���ͣ��c��λ�ô�
}

void setColor(unsigned short ForeColor = 7,unsigned short BackGroundColor = 0)//��ɫ���ú���
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //Windows API ����
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);  
}

class GameSetting
{
public://������Ϸ���ڵĳ���
	static const int window_height ;  
	static const int window_width ;   //��̬��Ա����
public:
	static void GameInt()
	{
		//������Ϸ���ڴ�С
		char buffer[32];
		sprintf(buffer,"more con cols=%d lines=%d",window_width,window_height);
		system(buffer);
	

	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle,&CursorInfo); //��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle,&CursorInfo);//���ÿ���̨���״̬
	//��ʼ�����������
	srand((unsigned int ) time(0));
	}
};

const int GameSetting::window_height=40;
const int GameSetting::window_width=80;

class PrintInfo
{
public:
	static void DrawChoiceInfo();  //ѡ��ģʽ
	static void	DrawMap();		   //������ͼ�߽�
	static void GameOver(int score);//��Ϸ����
	static void DrawScore(int score);//��ʾ����
	static void DrawGameInfo(bool model);//��ʾ��Ϸ����˵��
};

void PrintInfo::DrawChoiceInfo()
{
	gotoxy(GameSetting::window_width/2 - 10,GameSetting::window_height/2 - 7);
	cout<<"1�����ģʽ"<<endl;

	gotoxy(GameSetting::window_width/2 - 10,GameSetting::window_height/2 - 5);
	cout<<"2��AIģʽ"<<endl;
	
	gotoxy(GameSetting::window_width/2 - 10,GameSetting::window_height/2 - 9);
	cout<<"���������ѡ��"<<endl;
	
	
}

void PrintInfo::DrawMap()
{
		system("cls"); //����
		int i,j;
		for (i=0;i<GameSetting::window_width;i++)
		{
			cout<<"#";
		}
		cout<<endl;
		for (i=0;i<GameSetting::window_height-2;i++)
		{
			for (j=0;j<GameSetting::window_width;j++)
			{
				if (i==13&&j>=GameSetting::window_width-29)
				{
					cout<<"#";
					continue;
				}
				if (j==0 || j == GameSetting::window_width-29 || j == GameSetting::window_width-1)
				{
					cout<<"#";
				}
				else
					cout<<" ";
			}
			cout<<endl;
		}
		for (i=0;i<GameSetting::window_width;i++)
			cout<<"#";
}

void PrintInfo::GameOver(int score)
{
	setColor(12,0);   //����Ϊ��ɫ
	gotoxy(GameSetting::window_width/2 - 20,GameSetting::window_height / 2 - 5);
	cout<<"��Ϸ������"<<endl;
	gotoxy(GameSetting::window_width / 2 -20,GameSetting::window_height / 2 -3);
	cout<<"���ĵ÷�Ϊ��"<<score<<endl;
}

void PrintInfo::DrawScore(int score)
{
	gotoxy(GameSetting::window_width-22+14,6);
	cout<<" ";
	gotoxy(GameSetting::window_width-22+14,4);
	cout<<" ";

	gotoxy(GameSetting::window_width-22,6);
	cout<<"��ǰ��ҷ�����"<<score<<endl;
	gotoxy(GameSetting::window_width-22,4);
	cout<<"��ǰ��Ϸ�ٶȣ�"<<10-speed/25<<endl;
}

void PrintInfo::DrawGameInfo(bool model)
{
	gotoxy(GameSetting::window_width - 22, 8);
	if (model)
	{
		cout<<"��ǰ��Ϸģʽ��"<<"���ģʽ"<<endl;
	}
	else
	{
		cout<<"��ǰ��Ϸģʽ��"<<"AIģʽ"<<endl;
	}

	gotoxy(GameSetting::window_width - 22, 18);
	cout<<"��Ϸ����˵����"<<endl;

	gotoxy(GameSetting::window_width - 22, 20);
	cout<<"W:��    S:��"<<endl;

	gotoxy(GameSetting::window_width - 22, 23);
	cout<<"A:��    D:��"<<endl;

	gotoxy(GameSetting::window_width - 22, 26);
	cout<<"������Ϸ�ٶȣ�"<<endl;

	gotoxy(GameSetting::window_width - 22, 29);
	cout<<"С���� + ���ӿ�"<<endl;

	gotoxy(GameSetting::window_width - 22, 32);
	cout<<"С���� - ������"<<endl;

}

/*struct COORDINATE  //���꺯��
{
	int x;
	int y;
};*/

class Food
{
private:
	COORDINATE m_coordinate; // ʳ������
public:

	Food() {} // Ĭ�Ϲ��캯��
	void RandomXY(vector<COORDINATE> & coord);//���귶Χ
	Food(vector<COORDINATE> & coord) //���λ������ʳ��
	{
		RandomXY(coord);
	}
	void DrawFood();   //����ʳ��λ��
	COORDINATE GetFoodCoordinate()  //��ȡʳ��λ��
	{
		return m_coordinate;
	}
	int GetFoodX()
	{
		return m_coordinate.x;
	}
	int GetFoodY()
	{
		return m_coordinate.y;
	}
};

void Food::RandomXY(vector<COORDINATE> & coord)
{
	m_coordinate.x = rand() % (GameSetting::window_width - 30) + 1;
	m_coordinate.y = rand() % (GameSetting::window_height - 2) + 1;
	unsigned int i;
	for (i=0;i<coord.size();i++) //���ʳ���������������λ����Ҫ��������
	{
		if (coord[i].x==m_coordinate.x && coord[i].y == m_coordinate.y)
		{
			m_coordinate.x = rand() % (GameSetting::window_width - 30) + 1;
			m_coordinate.y = rand() % (GameSetting::window_height - 2) + 1;
			i=0;
		}
	}
}



void Food::DrawFood()   
{
	setColor(12,0);
	gotoxy(m_coordinate.x,m_coordinate.y);
	cout<<"@";
	setColor(7,0);
}

class Snake
{
private:
	bool m_model; //��Ϸģʽ���ã�true ��ң�false AI
	int m_direction;  //�ߵ��ƶ�����
	bool m_is_alive;  //�ж�̰�����Ƿ񻹻���
private://AI�������
	bool m_chess[GameSetting::window_width- 29 + 1][GameSetting::window_height];//AI������
	FindPathBFS m_AISnake;
	COORDINATE map_size;
public: //��������
	vector<COORDINATE> m_coordinate;

public:
	Snake(bool model = false) //Ĭ�Ϲ��캯����Ĭ��AIģʽ
	{
		m_direction = 1; // Ĭ������
		m_is_alive = true;//��ʼ�ߴ��
		COORDINATE  snake_head;//��ͷ
		snake_head.x = GameSetting::window_width/2 - 15; 
		snake_head.y = GameSetting::window_height/2;     //ȷ����ͷλ��

		this->m_coordinate.push_back(snake_head);
		snake_head.y++;
		this->m_coordinate.push_back(snake_head);
		snake_head.y++;
		this->m_coordinate.push_back(snake_head); //��ʼ������Ϊ3

		for (int i=0;i<GameSetting::window_width - 29 + 1 ; i++)
		{
			m_chess[i][0]= true;
			m_chess[i][GameSetting::window_height - 1] = true;
		} //�����߽�

		for (int j=0 ; j < GameSetting::window_height - 1; j++)
		{
			m_chess[0][j] = true;
			m_chess[GameSetting::window_width-29][j] = true;
		}//�����߽�
	}
	void set_model(bool m) {m_model = m;}//������Ϸģʽ
	void listen_key_board();//��������
//	void AI_speed();//AI����
	void AI_find_path(Food &f);//AI����
	bool self_collision(COORDINATE head);//������ײ���
	void AI_move_snake(Food &f);//AI����
	void move_snake();
	bool is_eat_food(Food & f);
	bool snake_is_alive();
	void draw_snake();
	void ClearSnake();
	int GetSnakeSize();
	bool GetModel();
};

void Snake::listen_key_board()
{
	char ch;
	if (_kbhit())//����Ƿ��м���
	{
		ch =_getch(); //�õ��������
		switch(ch)
		{
		case 'w':
		case 'W':
			if (this->m_direction == DOWN)
				break;//����
			this->m_direction = UP; //����
			break;
		case's':
		case'S':
			if (this->m_direction == UP)
				break;
			this->m_direction = DOWN;
			break;
		case'a':
		case'A':
			if (this->m_direction == RIGHT)
				break;
			this->m_direction = LEFT;
			break;
		case'd':
		case'D':
			if (this->m_direction == LEFT)
				break;
			this->m_direction = RIGHT;
			break;
		case '+':
			if (speed>=0) //speed������ʱ�䣬ʱ��Խ���ٶ�Խ��
			{
				speed-=25;
			}
		case '-':
			if (speed<250)
			{
				speed+=25;
			}
			break;
		}
	}
}



void Snake::AI_find_path(Food &f)
{
	static int not_found = 1;
	COORDINATE fpoint = f.GetFoodCoordinate();//��ȡʳ��λ��

	for (unsigned int i=0; i<m_coordinate.size();i++)
	{
		m_chess[m_coordinate[i].x][m_coordinate[i].y] = true;
	}
	COORDINATE begin_point, end_point;

	begin_point = m_coordinate[HEAD]; 
	end_point = fpoint; //ȷ����ʼ�����ֹ��

	m_AISnake.InitMap((bool**)m_chess);//��ʼ����ͼ
	m_AISnake.GetPath(begin_point, end_point);//Ѱ��·��
}

bool Snake::self_collision(COORDINATE head)
{
	for (unsigned int i=1;i<m_coordinate.size();i++)
	{
		if (head.x == m_coordinate[i].x && head.y == m_coordinate[i].y) //������ײ
		{
			return true;
		}
	}
	return false;
}

void Snake::AI_move_snake(Food &f)
{
	static int cot = 0;
	COORDINATE head,temp;
	if (!m_AISnake.m_paths_queue.empty())
	{
		head = m_AISnake.m_paths_queue.front();
		m_AISnake.m_paths_queue.pop();
	}
	else
	{
		for (int i = 0; i < 4;i++)
		{
			int break_num = rand() % 4;	
			temp = m_coordinate[HEAD];
			int t1=f.GetFoodX(); int t2=f.GetFoodY();
			double d=(temp.x-t1)*(temp.x-t1)+(temp.y-t2)*(temp.y-t2);
			temp.x = temp.x + dir[i][0];
			temp.y = temp.y + dir[i][1];
			
			
			if (temp.x<=0 ||
				(temp.x>=(GameSetting::window_width-2))||
				temp.y<=0 ||
				(temp.y>=(GameSetting::window_height-1))||
				self_collision(temp)||(((temp.x-t1)*(temp.x-t1)+(temp.y-t2)*(temp.y-t2))>d))//·����ͨ
			{
				
				continue;
			}
				head = temp;
			if (break_num == i)
				break;
		}
	}
		

	m_coordinate.insert(m_coordinate.begin(),head);
}

void Snake::move_snake()
{
	listen_key_board();//��������
	COORDINATE head = m_coordinate[0];//ȷ����ͷ
	switch (this->m_direction)
	{
	case UP:
		head.y--;  //��ͷ����
		break;
	case DOWN:
		head.y++;//��ͷ����
		break;
	case LEFT:
		head.x--;//��ͷ����
		break;
	case RIGHT:
		head.x++;//��ͷ����
	}
	m_coordinate.insert(m_coordinate.begin(),head); //�����µ���ͷ
													//�Ƿ�ɾ����β��ʳ�����д���
}

bool Snake::is_eat_food(Food &f) 
{
	COORDINATE food_coordinate = f.GetFoodCoordinate(); //ʳ��λ��
	if (m_coordinate[HEAD].x== food_coordinate.x && m_coordinate[HEAD].y == food_coordinate.y)
	{                              
		f.RandomXY(m_coordinate);
		return true;
	}//�Ե�ʳ��������ʳ��
	else
	{
		m_coordinate.erase(m_coordinate.end()-1);
		return false;
	}//û�гԵ�ʳ�ȥ����β
}

bool Snake::snake_is_alive()
{
	if (m_coordinate[HEAD].x<=0 ||
		m_coordinate[HEAD].x>=GameSetting::window_width-29||
		m_coordinate[HEAD].y<=0 ||
		m_coordinate[HEAD].y>=GameSetting::window_height-1)//����Ƿ�ײ��ǽ��
	{
		m_is_alive = false;  
		return m_is_alive;
	}
	for (unsigned int i	= 1;i<m_coordinate.size();i++)
	{
		if (m_coordinate[i].x == m_coordinate[HEAD].x && m_coordinate[i].y == m_coordinate[HEAD].y)
		{//����Ƿ���ײ
			m_is_alive = false;
			return m_is_alive;
		}
	}
	m_is_alive = true;

	return m_is_alive;
}


void Snake::draw_snake()
{
	setColor(10,0); //������ɫ
	for (unsigned int i=0;i<this->m_coordinate.size();i++)//��ӡ����
	{
		gotoxy(m_coordinate[i].x,m_coordinate[i].y);
		cout<<"*";
	}
	setColor(7,0); 
}

void Snake::ClearSnake()
{
	for (unsigned int i = 0;i < m_coordinate.size(); i++)
	{
		m_chess[m_coordinate[i].x][m_coordinate[i].y] = false;
	}
	gotoxy(m_coordinate[this->m_coordinate.size()-1].x,m_coordinate[this->m_coordinate.size()-1].y);
	cout<<" ";//�����β
}

int Snake::GetSnakeSize()
{
	return m_coordinate.size();
}

bool Snake::GetModel()
{
	return m_model;
}

int main()
{
	GameSetting setting;
	PrintInfo print_info;
	Snake snake;			//��ʼ����Ϸ
	setting.GameInt();		//ģʽѡ��
											
	print_info.DrawChoiceInfo(); //��ӡѡ����Ϸģʽ��Ϣ
									
	char ch=_getch();
	switch (ch)
	{
	case '1':
		snake.set_model(true);
		speed = 50;
		break;
	case '2':
		snake.set_model(false);
		speed = 80;
		break;
	default:
		gotoxy(GameSetting::window_width / 2 -10,GameSetting::window_height / 2 + 3);
		cout<< "�������!"<<endl;
		cin.get();
		cin.get();
		return 0;
	}
	gotoxy(GameSetting::window_width / 2 - 10,GameSetting::window_height / 2 + 3);
	system("pause");//��ͣ�ڴ���

	print_info.DrawMap();  // ����ͼ
	print_info.DrawGameInfo(snake.GetModel());  //��ʾ��Ϸ��Ϣ
	Food food(snake.m_coordinate); //����ʳ��


	while (true) //��Ϸ��ѭ��
	{
		print_info.DrawScore(snake.GetSnakeSize());   //ˢ�³ɼ�
		food.DrawFood();	//����ʳ��
		snake.ClearSnake(); //������β
		snake.is_eat_food(food);//�ж��Ƿ�Ե�ʳ��
		if (snake.GetModel() == true)//�û�ģʽѡ���ж�
		{
			snake.move_snake();
		}
		else
		{
			snake.AI_find_path(food);
			snake.AI_move_snake(food);
		}
		snake.draw_snake(); //����
		if (!snake.snake_is_alive()) //�ж����Ƿ񻹻���
		{
			print_info.GameOver(snake.GetSnakeSize());
			break;
		}
		Sleep(speed); //������Ϸ�ٶ�
	}
	cin.get();
	cin.get();
}