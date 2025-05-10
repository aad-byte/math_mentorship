import tkinter as tk


class GraphEditor:
    def __init__(self, master):
        self.master = master
        self.canvas = tk.Canvas(master, width=800, height=600, bg="white")
        self.canvas.pack()

        self.nodes = {}  # node_id -> (x, y)
        self.edges = []  # list of (node1_id, node2_id)
        self.node_id = 0
        self.selected_node = None

        self.canvas.bind("<Button-1>", self.on_click)

        # Button to print the adjacency matrix
        self.button = tk.Button(
            master, text="Print Adjacency Matrix", command=self.print_matrix
        )
        self.button.pack()

    def on_click(self, event):
        for nid, (x, y) in self.nodes.items():
            if (event.x - x) ** 2 + (event.y - y) ** 2 < 400:
                if self.selected_node is None:
                    self.selected_node = nid
                else:
                    if (self.selected_node, nid) not in self.edges and (
                        nid,
                        self.selected_node,
                    ) not in self.edges:
                        self.edges.append((self.selected_node, nid))
                    self.selected_node = None
                    self.redraw()
                return

        # Create a new node
        self.nodes[self.node_id] = (event.x, event.y)
        self.node_id += 1
        self.redraw()

    def redraw(self):
        self.canvas.delete("all")

        # Draw edges
        for n1, n2 in self.edges:
            x1, y1 = self.nodes[n1]
            x2, y2 = self.nodes[n2]
            self.canvas.create_line(x1, y1, x2, y2)

        # Draw nodes
        for nid, (x, y) in self.nodes.items():
            self.canvas.create_oval(x - 20, y - 20, x + 20, y + 20, fill="lightblue")
            self.canvas.create_text(x, y, text=str(nid))

    def print_matrix(self):
        size = len(self.nodes)
        matrix = [[0] * size for _ in range(size)]
        for n1, n2 in self.edges:
            matrix[n1][n2] = 1
            matrix[n2][n1] = 1  # undirected graph
        print("Adjacency Matrix:")
        for row in matrix:
            print(" ".join(map(str, row)))


if __name__ == "__main__":
    root = tk.Tk()
    root.title("Graph Editor")
    editor = GraphEditor(root)
    root.mainloop()
