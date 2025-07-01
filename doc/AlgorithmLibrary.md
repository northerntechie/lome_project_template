---
header-includes:
  - \usepackage{listings}
  - \usepackage{tikz}
  - \usepackage{caption}
  - \usepackage{subcaption}
  - \usepackage{makecell}
  - \usepackage{pgf-umlsd}
  - \usepgflibrary{arrows}
  - \usetikzlibrary{graphdrawing}
  - \usetikzlibrary{graphs}
  - \usegdlibrary{trees}
  - \lstset{
      basicstyle=\ttfamily,
      numbersep=15pt,
      breaklines=true
    }
  - '<style>
      code { font-family: monospace; }
      center { text-align: center; }
    </style>'
  - \usepackage[ruled,vlined]{algorithm2e}
---

\begin{center}
	\large{\textbf{MathAlgorithm}} \\
	\textbf{A General Purpose Math and Algorithm Library}
	\vfill
\end{center}

![](doc/images/Simple_treadle_floorloom_line_drawing.png){ width=100%}

\pagebreak

# Introduction

The MathAlgorithm library provides commonly used math and algorithms used in Computer Science education in the C++ language. This book provides the documentation of the Library. Images, diagrams along with mathematical concepts are provided throughout.

# `Algorithm` namespace

The `Algorithm` namespace provides a collection of algorithm operations that include sorting, partition, operations on sets among other operations.

## Insertion Sort

The library provides an __Insertion Sort__ implementation through the `insertion_sort()` function.

<hr style="border:2px solid">```cpp {.numberLines startFrom=20 }
void insertion_sort(std::vector<Data>& arr)
	{
		for (std::size_t i=1; i < arr.size(); ++i) {
			insert(arr, i, arr[i]);
		}
	}
```
<hr style="border:2px solid">
The `insert()` function is implemented as,

<hr style="border:2px solid">```cpp {.numberLines startFrom=8 }
void insert(std::vector<Data>& arr, std::size_t pos, Data& value)
	{
		std::size_t i = pos - 1;

		while ( (i >= 0) && (arr[i] > value) ) {
			arr[i + 1] = arr[i];
			--i;
		}

		arr[i + 1] = value;
	}
```
<hr style="border:2px solid">
The __Insertion Sort__ algorithm can be described as,

The complexity of the insertion sort algorithm is $O(n)$ for best case, $O(n^2)$ for average case and $O(n^2)$ for the worst case. The complexity is driven by the single while loop in the worst case,

<hr style="border:2px solid">```cpp {.numberLines startFrom=12 }
		while ( (i >= 0) && (arr[i] > value) ) {
			arr[i + 1] = arr[i];
			--i;
		}

```
<hr style="border:2px solid">
# Graph Algorithms

Graph algorithms require data structures to represent input, intermediate, and output data. The library provides various data structures for the user to use to represent graph data. Here are the various data structures available in the library.

## `Edge` Data Structure

The `Edge` data structure is used to represent an edge `(u,v)` between two vertices `u` and `v` in a graph. It is the base type that has different derived types depending on usage.

<!-- This is an example of a Latex table -->
\begin{center}
\begin{tabular}{ |l| }
	\hline
	\texttt{Edge} \\
	\hline
	\texttt{+u: int} \\
	\texttt{+v: int} \\
	\texttt{+weight: float} \\
	\hline
\end{tabular}
\end{center}

The starting or first vertex is identified by a unique integer value of $u$, and the ending or next vertex is identified as $v$. A weight is also provided to allow for edge weighted graph representation. A vertex can have many edges in a graph, so the value of $u$ can appear many times. A sequence of edges could be represented by ${ (u_0, v_0, w_0), (u_0, v_1, w_1), (u_0, v_2, w_2) }$.

## `Graph` class

A graph is represented as a `Graph` class which encapsulates the graph data and provides unary operations, getters and setters.

\begin{center}
\begin{tabular}{ |l| }
	\hline
	\texttt{Graph} \\
	\hline
		\texttt{-maxVertices: int} \\
		\texttt{-directed: bool} \\
		\texttt{-edges: list<Edge>} \\
	\hline
		\texttt{+Graph(int maxVertices, bool directed = false)} \\
		\texttt{+load(std::string\_view fileName): bool} \\
		\texttt{+isDirected(): bool} \\
		\texttt{+numVertices(): int} \\
		\texttt{+isEdge(int u, int v): bool} \\
		\texttt{+edgeWeight(int u, int v): float} \\
		\texttt{+addEdge(int u, int v, float weight): bool} \\
		\texttt{+removeEdge(int u, int v): bool} \\
		\texttt{+friend operator<<(std::ostream\& os, const Graph\& graph): std::ostream\&} \\
	\hline
\end{tabular}
\end{center}

\pagebreak

An simple example of using the graph and an external json file to load is,

<hr style="border:2px solid">```cpp {.numberLines startFrom=19 }

		graph.load("data/test.json");
		std::cout << "\tOutput: ";
		std::cout << graph;


```
<hr style="border:2px solid">
The output is,

		Output: { (1,2),(2,3),(1,4), }

And the json file is,

```json
[
	{
		"u" : 1,
		"v" : 2,
		"weight" : 1.0
	},
	{
		"u" : 2,
		"v" : 3,
		"weight" : 0.5
	},
	{
		"u" : 1,
		"v" : 4,
		"weight" : 1.0
	}
]
```
\pagebreak

\begin{figure}[ht!]
	\centering
	\begin{subfigure}[t]{0.49\textwidth}
		\centering
		\begin{tikzpicture}[>=stealth]
			\matrix [column sep=5mm,row sep=5mm]
			{
				% row 1
				\node (1) [circle, draw, minimum size=0.5cm] {1}; & &
				\node (2) [circle, draw, minimum size=0.5cm] {2}; &
				\node (3) [circle, draw, minimum size=0.5cm] {3}; \\

				% row 2
				& \node (5) [circle, draw, minimum size=0.5cm] {5}; & &
				\node (8) [circle, draw, minimum size=0.5cm] {8}; \\

				% row 3
				\node (0) [circle, draw, minimum size=0.5cm] {0}; &
				\node (4) [circle, draw, minimum size=0.5cm] {4}; &
				\node (3) [circle, draw, minimum size=0.5cm] {3}; &
				\node (7) [circle, draw, minimum size=0.5cm] {7}; \\
			};

			\draw (1) -- (2);
			\draw (2) -- (3);
			\draw (0) -- (1);
			\draw (0) -- (4);
			\draw (4) -- (5);
			\draw (4) -- (3);
			\draw (3) -- (2);
			\draw (8) -- (7);
		\end{tikzpicture}
		\caption{Initial graphs state}
	\end{subfigure}
	\hfill
	\begin{subfigure}[t]{0.45\textwidth}
		\centering
		\begin{tikzpicture}[>=stealth]
			\matrix [column sep=5mm,row sep=5mm]
			{
				% row 1
				\node (1) [fill=gray!20, circle, draw, minimum size=0.5cm] {1}; & &
				\node (2) [fill=gray!20, circle, draw, minimum size=0.5cm] {2}; &
				\node (6) [circle, draw, minimum size=0.5cm] {6}; \\

				% row 2
				& \node (5) [fill=gray!20, circle, draw, minimum size=0.5cm] {5}; & &
				\node (8) [circle, draw, minimum size=0.5cm] {8}; \\

				% row 3
				\node (0) [fill=gray!20, circle, draw, minimum size=0.5cm] {0}; &
				\node (4) [fill=gray!20, circle, draw, minimum size=0.5cm] {4}; &
				\node (3) [fill=gray!20, circle, draw, minimum size=0.5cm] {3}; &
				\node (7) [circle, draw, minimum size=0.5cm] {7}; \\
			};

			\draw (1) -- (2);
			\draw (2) -- (3);
			\draw (2) -- (6);
			\draw (0) -- (1);
			\draw (0) -- (4);
			\draw (4) -- (5);
			\draw (4) -- (3);
			\draw (3) -- (2);
			\draw (8) -- (7);
		\end{tikzpicture}
		\caption{\_dfs\_visit() of each node coloring}
	\end{subfigure}
	\\
	\begin{subfigure}[t]{0.40\textwidth}
		\centering
		\begin{tikzpicture}[>=stealth]
			\matrix [column sep=5mm,row sep=5mm]
			{
				% row 1
				\node (1) [fill=gray!20, circle, draw, minimum size=0.5cm] {1}; & &
				\node (2) [fill=gray!20, circle, draw, minimum size=0.5cm] {2}; &
				\node (6) [circle, draw, minimum size=0.5cm] {6}; \\

				% row 2
				& \node (5) [text=white, fill=black, circle, draw, minimum size=0.5cm] {5}; & &
				\node (8) [circle, draw, minimum size=0.5cm] {8}; \\

				% row 3
				\node (0) [fill=gray!20, circle, draw, minimum size=0.5cm] {0}; &
				\node (4) [text=white, fill=black, circle, draw, minimum size=0.5cm] {4}; &
				\node (3) [text=white, fill=black, circle, draw, minimum size=0.5cm] {3}; &
				\node (7) [circle, draw, minimum size=0.5cm] {7}; \\
			};

			\draw (1) -- (2);
			\draw (2) -- (3);
			\draw (2) -- (6);
			\draw (0) -- (1);
			\draw (0) -- (4);
			\draw (4) -- (5);
			\draw (4) -- (3);
			\draw (3) -- (2);
			\draw (8) -- (7);
		\end{tikzpicture}
		\caption{\_dfs\_visit() with some\\finished vertices}
	\end{subfigure}
	\hfill
	\begin{subfigure}[t]{0.40\textwidth}
		\centering
		\begin{tikzpicture}[>=stealth]
			\matrix [column sep=5mm,row sep=5mm]
			{
				% row 1
				\node (1) [text=white, fill=black, circle, draw, minimum size=0.5cm] {1}; & &
				\node (2) [text=white, fill=black, circle, draw, minimum size=0.5cm] {2}; &
				\node (6) [text=white, fill=black, circle, draw, minimum size=0.5cm] {6}; \\

				% row 2
				& \node (5) [text=white, fill=black, circle, draw, minimum size=0.5cm] {5}; & &
				\node (8) [text=white, fill=black, circle, draw, minimum size=0.5cm] {8}; \\

				% row 3
				\node (0) [text=white, fill=black, circle, draw, minimum size=0.5cm] {0}; &
				\node (4) [text=white, fill=black, circle, draw, minimum size=0.5cm] {4}; &
				\node (3) [text=white, fill=black, circle, draw, minimum size=0.5cm] {3}; &
				\node (7) [text=white, fill=black, circle, draw, minimum size=0.5cm] {7}; \\
			};

			\draw [->] (2) -- (1);
			\draw [->] (3) -- (2);
			\draw [->] (6) -- (2);
			\draw [->] (1) -- (0);
			\draw [->] (5) -- (4);
			\draw [->] (4) -- (3);
			\draw [->] (3) -- (2);
			\draw [->] (8) -- (7);
		\end{tikzpicture}
		\caption{\_dfs\_visit() final state}
	\end{subfigure}
	\captionof{figure}{Depth-first search example}
\end{figure}


The $\texttt{Algo::dfs(const Types::Graph\& graph, int startId, std::vector<int>\& predecessor)}$ function provides the $\texttt{DEPTH-FIRST SEARCH}$ algorithm on a graph object and outputs a predecessor list to determine the paths taken back to the start for each child vertices.

<hr style="border:2px solid">```cpp {.numberLines startFrom=17 }
void dfs(const Types::Graph& graph, int s, std::vector<int>& predecessor) {
		std::vector<int> vertices = graph.getVertices();
		std::vector<Types::VertexColor> color(vertices.size());
		std::vector<int> discovered(vertices.size());
		std::vector<int> finished(vertices.size());
		std::size_t counter = 0;

		std::fill(color.begin(), color.end(), Types::VertexColor::White);
		std::fill(discovered.begin(), discovered.end(), -1);
		std::fill(finished.begin(), finished.end(), -1);

		_dfs_visit(graph, discovered, finished, predecessor, color, s, counter);

		for (const auto v : vertices) {
			if (color[v] == Types::VertexColor::White) {
				_dfs_visit(graph, discovered, finished, predecessor, color, v, counter);
			}
		}
	}
```
<hr style="border:2px solid">
The `Algo::_dfs_visit(const Types::Graph& graph, std::vector<int>& discovered, std::vector<int>& finished, std::vector<int>& predecessor, std::vector<Types::VertexColor>& color, int id, std::size_t counter)` provides the recursive calls to walk the entire graph. The `discovered`, `finished`, `color` and the final ouput `predecessor` lists are passed through each `_dfx_visit(...)` call. These are free functions and not a class object. This implementation is for an explicit example of where the affected data structures are used.

The pseudo code for the $\texttt{DEPTH-FIRST SEARCH}$ is shown in Algorithm 1,

\begin{algorithm}
	\SetAlgoLined
	\KwData{Graph $V$, start vertex $s$}
	\KwResult{Arrays of $d$, discovered, $pred$, predecessor vertices, and $f$, finished counter}
	\Begin{
		\ForEach{$v \in V$}{
			d[v] = f[v] = pred[v] = -1\\
			color[v] = White\\
		}
		counter = 0\\
		\FuncSty{dfs\_visit(}\ArgSty{s}\FuncSty{)}\\

		\ForEach{$v \in V$}{
			\If{color[v] = White}{
				\FuncSty{dfs\_visit(}\ArgSty{v}\FuncSty{)}\\
			}
		}
	}
	\BlankLine
	\FuncSty{dfs\_visit(}\ArgSty{u}\FuncSty{)} \\
	\Begin{
		color[u] = Gray \\
		d[u] = ++counter \\
		\For{each neighbor v of u}{
			\If{color[v] = White}{
				pred[v] = u \\
				\FuncSty{dfs\_visit(}\ArgSty{v}\FuncSty{)}
			}
		}
		color[u] = black \\
		f[u] = ++counter
	}
	\caption{DEPTH-FIRST SEARCH}
	\label{depthFirst0}
\end{algorithm}

An easier method of supplying a depth first search algorithm on a graph object is to wrap the operation in a class object to hide the implementation details. That can be seen in the `Algo::DepthFirstSearch` class that takes in a graph object and returns the predecessor list in a search function.

The complexity of the DEPTH-FIRST SEARCH algorithm is show in Table 1.

\begin{table}[h]
	\centering
	\setcellgapes{5pt}
	\makegapedcells
	\begin{tabular}{|c|c|c| }
		\hline
		\texttt{Best} & \texttt{Average} & \texttt{Worst} \\
		\hline
		$O(V+E)$ & $O(V+E)$ & $O(V+E)$ \\
		\hline
	\end{tabular}
	\caption{DEPTH-FIRST SEARCH complexity}
\end{table}

# `TaskManager` helper class

The `TaskManager` class provides a simple task management to allow tasks to use an underlying thread pool within the class implementation to run algorithms in a parallel manner.

The sequence diagram in Figure 1 shows the interaction between the task build and the thread pool implementation.

\begin{figure}
	\centering

	\begin{sequencediagram}
		\newthread{tm}{:TaskManager}
		\newinst[1.5]{th0}{:Thread0}
		\newinst[1.5]{th1}{:Thread1}
		\newinst[1.5]{thn}{:Threadn}

		\begin{sdblock}{Run Loop}{The main loop}
			\begin{call}{tm}{run(...)}{th0}{completed()}
				\begin{call}{tm}{run(...)}{th1}{completed()}
				\end{call}
			\end{call}
		\end{sdblock}
  \end{sequencediagram}

  \caption{TaskManager \texttt{run} sequence diagram}
\end{figure}

The `TaskManager` class has a `run(...)` function that takes in both a task as a `std::function<void()>` and a completed callback that is used to examine a `TaskManager::Result` enumeration and execute code as a result. The implementation is,

<hr style="border:2px solid">```cpp {.numberLines startFrom=19 }
void TaskManager::run(
	std::string_view label,
	std::function<Result()>&& task,
	std::function<void(Result&)> completed)
{
	auto thread_entry_point = [](
		std::function<Result()>&& func,
		std::function<void(Result&)> completed)
	{
		Result result = func();
		completed(result);
	};
	std::jthread worker(thread_entry_point, std::move(task), completed);
	worker.detach();
}
```
<hr style="border:2px solid">
`// This is a comment that appears in the documentation only`
<hr style="border:2px solid">```cpp {.numberLines startFrom=19 }
void TaskManager::run(

```
<hr style="border:2px solid">This is regular body text description, the `std::string_view` is used as a label as the underlying string is in static storage as a literal. We should use `std::string_view` over `const std::string&` where we can.
<hr style="border:2px solid">```cpp {.numberLines startFrom=20 }
	std::string_view label,

```
<hr style="border:2px solid">