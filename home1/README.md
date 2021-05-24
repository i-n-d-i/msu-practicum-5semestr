## first homework - введение
#### 1-Ложки Серёжки 
Условие:  Серёжа очень любит ложки. Только получит очередную зарплату - сразу бежит в магазин посуды! Кроме страсти к весьма незамысловатым столовым приборам, Серёжа любит деревья. Особенно, двоичные. В связи с этим, он хочет все свои коллекционные экземпляры выложить на стене (вместо зависевшегося там ковра) в виде полного двоичного дерева. Сейчас у Серёжи N ложек, и он хочет выяснить, какой высоты полное двоичное дерево он прямо сейчас сможет выложить на своей стене. А если у Серёжи после такой выкладки останутся ещё лишние ложки, то он хочет знать, сколько ему нужно их докупить, чтобы выложить дерево на единицу большей глубины.

В первой строке входных данных содержится одно целое число: N (1 ≤ N ≤ 10^9).

Требуется вывести два целых числа: D - глубина полного двоичного дерева, C - число ложек, которое необходимо докупить для построения дерева большей глубины. Если после построения полного двоичного дерева глубины D ложек не остаётся, то полагаем C равным нулю. 

#### 2-Пирамида 
Условие: В одной из 117 в наши дни известных альтернативных вселенных Тутанхамон решил построить себе пирамиду весьма странным образом. Однажды, он совершенно неясно где откопал одномерный массив, состоящий из N целых неотрицательных чисел a1, ..., aN. После этого Тутанхамон решил поступить следующим образом. Он хочет выбрать некоторый префикс массива a1, ..., ai длины i, затем построить левую часть по такому принципу: первая ступень будет высоты a1, вторая — высоты a1 + a2, ..., i-я ступень — высоты a1 + ... + ai. Правая часть строится по аналогичному принципу, только действия происходят с оставшимся суффиксом массива: последняя ступень оказывается высоты aN, предпоследняя — высоты aN + aN - 1, и т.д. Например, пусть фараоном был откопан массив чисел 1, 3, 4, 2, 1, 2 и он выбирает префикс длины 3. Тогда высоты ступеней пирамиды будут следующими: 1, 4, 8, 5, 3, 2.

Фараон оказался очень скромным и поэтому не хочет, чтобы его пирамида была слишком высокой. Наоборот, он хочет построить пирамиду наименьшей возможной высоты. Помогите посчитать ему данную величину!

В первой строке входных данных содержится одно целое число: N (1 ≤ N ≤ 106). В следующей строке содержатся N целых неотрицательных чисел a1, ..., aN (0 ≤ ai ≤ 109, i = 1, ..., N).

Требуется вывести одно целое число — минимально возможную высоту пирамиды. Обратите внимание, что это число может быть велико и 32-битного типа данных может быть недостаточно.

#### 3-Нужно построить Зиккурат
Условие: На самом деле Зиккурат уже построили, и требуется решить совсем другую задачу. Лидеры ПЖиВ хотят знать, сколько депутатов смогут одновременно приземлиться на крышу Зиккурата, то есть от Вас требуется посчитать число вертолётных площадок.

Крыша Зиккурата представляет собой прямоугольную область, состоящую из N х M клеток. Каждая клетка может быть покрашена либо в белый, либо в чёрный цвет. Во входных данных белый цвет обозначен символом '.', а чёрный - '#'. Вертолётной площадкой считается область, не имеющая соседних чёрных клеток и размеченная следующим образом:
#.#
###
#.#

В первой строке входных данных содержатся два целых числа: N (1 ≤ N ≤ 1000) и M (1 ≤ M ≤ 1000). Следующие N строк входных данных содержит строки длины M, описывающие крышу Зиккурата. Символ '.' означает, что соответствующая клетка имеет белый цвет, а символ '#' обозначает клетку, покрашенную в чёрный цвет.

Требуется вывести одно целое число - число вертолётных площадок на крыше Зиккурата. 

#### 4-Числа Каббоначи
Условие:  Вы же любите пасту "карбонара"? Ну, которую ещё усатый дядя Паша в столовой ГЗ накладывает? Но, к сожалению, задача не про это, а про обобщение чисел Фибоначчи.

Напомним, что числа Фибоначчи определяются следующим образом: a0 = a1 = 1, a2 = a0 + a1, ..., ai = ai-2 + ai-1, ... . Мы же определим последовательность для произвольного натурального k > 1, в которой каждый член последовательности будет равен не сумме двух предыдущих, а сумме k предыдущих членов последовательности! Формально, a0 = ... = ak-1 = 1, ..., ai = ai-k + ... + ai-1, ... . Назовём данную последовательность числами k-боначчи.

Вам требуется вывести N-е число последовательности для заданного k. Ответ следует вывести по модулю простого числа 109 + 7.

В первой строке входных данных содержатся два целых числа: N (0 ≤ N ≤ 106) и k (2 ≤ k ≤ 10).

Требуется вывести одно целое число - N-й член последовательности k-боначчи по модулю 109 + 7. 

#### 7-DNS
Условие:  Владимир Анатольевич прекрасный оратор. С помощью невероятных риторических способностей ему удалось заключить с государством крупную сделку по реализации отечественного DNS-сервера. К сожалению, Владимир Анатольевич в течение многих лет не практиковался в программировании, поэтому он очень просит Вас помочь ему с этим очень важным для страны проектом!

DNS-сервер представляет собой систему, которая по адресу некоторого сайта (домену) возвращает IP-адрес нужного хоста. Например, если DNS-сервер получает запрос "vk.com" он может вернуть, например, строку "87.240.129.72". Таблица соответствия доменам их IP-адресов хранится в базе данных DNS-сервера.

В первой строке входных данных содержатся два целых числа: N - число записей в базе данных DNS-сервера (1 ≤ N ≤ 10^5) и M - число запросов к DNS-серверу (1 ≤ M ≤ 10^5). В следующих N строках содержатся записи из базы DNS-сервера. Каждая запись представляет собой пару строк domen (доменное имя сайта) и ip (IP-адрес хоста), разделённых пробелами. Гарантируется, что строки domen и ip содержат только маленькие латинские буквы, цифры и символы '.'. Также гарантируется, что в базе данных нет записей с совпадающими доменными именами. В следующих M строках содержатся запросы к DNS-северу. Каждый запрос представляет собой строку, состоящую из маленьких латинский букв, цифр и символов '.'.

Для каждого запроса требуется вывести IP-адрес хоста, соответствующий доменному имени, заданному в запросе. Если в базе данных DNS-сервера нет искомого домена, то нужно вывести строку "PUSTO".