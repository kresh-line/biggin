"""
Display 3D - 14.5 inch monitor
Hape këtë skedar në Blender: File > Open > display_14_5inch.py
ose nga terminali: blender --python display_14_5inch.py

Përmasat:
- Ekrani: 14.5 inç diagonale (16:9 aspect ratio)
- Korniza (bezel): 2 inç trashësi
- Para (front): e zezë
- Mbrapa (back): gri
"""

import bpy
import math

# ============================================================
# Pastro skenën
# ============================================================
bpy.ops.object.select_all(action='SELECT')
bpy.ops.object.delete(use_global=False)

# Fshi materialet e vjetra
for mat in bpy.data.materials:
    bpy.data.materials.remove(mat)

# ============================================================
# Llogarit përmasat nga inç në metra (Blender përdor metra)
# ============================================================
INCH_TO_M = 0.0254  # 1 inç = 0.0254 metra

diagonal_inch = 14.5
bezel_inch = 2.0  # trashësia e kornizës rreth ekranit

# Llogarit gjerësinë dhe lartësinë e ekranit (paneli LCD) nga diagonalja 16:9
aspect_w = 16
aspect_h = 9
aspect_diag = math.sqrt(aspect_w**2 + aspect_h**2)  # ~18.36

screen_w_inch = diagonal_inch * (aspect_w / aspect_diag)  # ~12.63 inç
screen_h_inch = diagonal_inch * (aspect_h / aspect_diag)  # ~7.11 inç

# Përmasa totale e monitorit (ekran + kornizë nga të dyja anët)
total_w_inch = screen_w_inch + 2 * bezel_inch
total_h_inch = screen_h_inch + 2 * bezel_inch

# Konverto në metra
total_w = total_w_inch * INCH_TO_M  # ~0.423 m
total_h = total_h_inch * INCH_TO_M  # ~0.282 m
screen_w = screen_w_inch * INCH_TO_M
screen_h = screen_h_inch * INCH_TO_M

# Trashësia e monitorit (thellësia)
depth_front = 0.005  # 5mm korniza e përparme
depth_body = 0.015   # 15mm trupi kryesor (mbrapa)
depth_total = depth_front + depth_body

# ============================================================
# Materialet
# ============================================================

# Material i zi (korniza e përparme / bezeli)
mat_black = bpy.data.materials.new(name="Korniza_Zezë")
mat_black.use_nodes = True
bsdf = mat_black.node_tree.nodes["Principled BSDF"]
bsdf.inputs["Base Color"].default_value = (0.01, 0.01, 0.01, 1.0)  # e zezë
bsdf.inputs["Roughness"].default_value = 0.3

# Material gri (mbrapa)
mat_gray = bpy.data.materials.new(name="Mbrapa_Gri")
mat_gray.use_nodes = True
bsdf_gray = mat_gray.node_tree.nodes["Principled BSDF"]
bsdf_gray.inputs["Base Color"].default_value = (0.35, 0.35, 0.35, 1.0)  # gri
bsdf_gray.inputs["Roughness"].default_value = 0.5

# Material për ekranin (LCD - pak reflektues)
mat_screen = bpy.data.materials.new(name="Ekrani_LCD")
mat_screen.use_nodes = True
bsdf_screen = mat_screen.node_tree.nodes["Principled BSDF"]
bsdf_screen.inputs["Base Color"].default_value = (0.02, 0.02, 0.05, 1.0)  # blu-zi i errët
bsdf_screen.inputs["Roughness"].default_value = 0.05  # shumë i lëmuar
bsdf_screen.inputs["Metallic"].default_value = 0.1

# ============================================================
# 1) Trupi kryesor i monitorit (drejtkëndësh i madh)
# ============================================================
bpy.ops.mesh.primitive_cube_add(
    size=1,
    location=(0, 0, 0)
)
body = bpy.context.active_object
body.name = "Monitor_Trupi"
body.scale = (total_w / 2, depth_total / 2, total_h / 2)
bpy.ops.object.transform_apply(scale=True)

# Vendos materialin gri për trupin (do ta mbulojmë përpara me kornizën e zezë)
body.data.materials.append(mat_gray)

# ============================================================
# 2) Korniza e përparme (bezel i zi)
# ============================================================
bezel_z_offset = depth_total / 2 + 0.0001  # pak përpara trupit

bpy.ops.mesh.primitive_cube_add(
    size=1,
    location=(0, -(depth_total / 2) + (depth_front / 2), 0)
)
bezel = bpy.context.active_object
bezel.name = "Korniza_Përparme"
bezel.scale = (total_w / 2, depth_front / 2, total_h / 2)
bpy.ops.object.transform_apply(scale=True)
bezel.data.materials.append(mat_black)

# Poziciono kornizën pak përpara
bezel.location.y = -(depth_total / 2) + (depth_front / 2)

# ============================================================
# 3) Ekrani (LCD paneli - futet brenda kornizës)
# ============================================================
bpy.ops.mesh.primitive_plane_add(
    size=1,
    location=(0, -(depth_total / 2) - 0.0005, 0)  # pak para kornizës
)
screen = bpy.context.active_object
screen.name = "Ekrani_LCD"
screen.scale = (screen_w / 2, 1, screen_h / 2)
bpy.ops.object.transform_apply(scale=True)
screen.rotation_euler.x = 0  # tashmë i drejtë
screen.data.materials.append(mat_screen)

# ============================================================
# 4) Paneli i pasmë (gri, me formë pak të dalë)
# ============================================================
bpy.ops.mesh.primitive_cube_add(
    size=1,
    location=(0, (depth_total / 2) - (depth_body / 2), 0)
)
back_panel = bpy.context.active_object
back_panel.name = "Paneli_Pasmë"
back_panel.scale = (total_w * 0.92 / 2, depth_body * 0.5 / 2, total_h * 0.85 / 2)
bpy.ops.object.transform_apply(scale=True)
back_panel.location.y = depth_total / 2 - 0.002
back_panel.data.materials.append(mat_gray)

# ============================================================
# 5) Baza / Këmba (stand)
# ============================================================

# Qafa (vertikal)
bpy.ops.mesh.primitive_cylinder_add(
    radius=0.012,
    depth=0.08,
    location=(0, 0.005, -(total_h / 2) - 0.04)
)
neck = bpy.context.active_object
neck.name = "Qafa"
neck.data.materials.append(mat_black)

# Baza (disk)
bpy.ops.mesh.primitive_cylinder_add(
    radius=0.07,
    depth=0.008,
    location=(0, 0.005, -(total_h / 2) - 0.08 - 0.004)
)
base = bpy.context.active_object
base.name = "Baza"
base.data.materials.append(mat_black)

# ============================================================
# 6) Logo e vogël në kornizë (poshtë, qendër)
# ============================================================
bpy.ops.mesh.primitive_cube_add(
    size=1,
    location=(0, -(depth_total / 2) - 0.001, -(total_h / 2) + bezel_inch * INCH_TO_M * 0.5)
)
logo = bpy.context.active_object
logo.name = "Logo"
logo.scale = (0.015, 0.001, 0.003)
bpy.ops.object.transform_apply(scale=True)

mat_logo = bpy.data.materials.new(name="Logo_Mat")
mat_logo.use_nodes = True
bsdf_logo = mat_logo.node_tree.nodes["Principled BSDF"]
bsdf_logo.inputs["Base Color"].default_value = (0.5, 0.5, 0.5, 1.0)
bsdf_logo.inputs["Metallic"].default_value = 0.9
logo.data.materials.append(mat_logo)

# ============================================================
# 7) Drita dhe kamera
# ============================================================

# Dritë kryesore (Key light)
bpy.ops.object.light_add(
    type='AREA',
    location=(0.3, -0.5, 0.3)
)
key_light = bpy.context.active_object
key_light.name = "Drita_Kryesore"
key_light.data.energy = 50
key_light.data.size = 0.5
key_light.rotation_euler = (math.radians(45), 0, math.radians(-20))

# Dritë plotësuese (Fill light)
bpy.ops.object.light_add(
    type='AREA',
    location=(-0.4, -0.3, 0.1)
)
fill_light = bpy.context.active_object
fill_light.name = "Drita_Plotësuese"
fill_light.data.energy = 20
fill_light.data.size = 0.3

# Dritë nga mbrapa (Rim light)
bpy.ops.object.light_add(
    type='POINT',
    location=(0, 0.5, 0.2)
)
rim_light = bpy.context.active_object
rim_light.name = "Drita_Pasme"
rim_light.data.energy = 30

# Kamera
bpy.ops.object.camera_add(
    location=(0.35, -0.55, 0.15),
    rotation=(math.radians(78), 0, math.radians(25))
)
camera = bpy.context.active_object
camera.name = "Kamera"
camera.data.lens = 50
bpy.context.scene.camera = camera

# ============================================================
# 8) Cilësimet e render-it
# ============================================================
scene = bpy.context.scene
scene.render.engine = 'CYCLES'
scene.cycles.samples = 128
scene.render.resolution_x = 1920
scene.render.resolution_y = 1080
scene.render.film_transparent = True  # sfond transparent

# Nëse nuk ka GPU, përdor CPU
scene.cycles.device = 'CPU'

# ============================================================
# Smooth shading për të gjitha objektet mesh
# ============================================================
for obj in bpy.data.objects:
    if obj.type == 'MESH':
        obj.select_set(True)
        bpy.context.view_layer.objects.active = obj
        bpy.ops.object.shade_smooth()
        obj.select_set(False)

# Fokusohu te monitori
bpy.ops.object.select_all(action='DESELECT')
body.select_set(True)
bpy.context.view_layer.objects.active = body

print("="*50)
print("  DISPLAY 14.5\" - U KRIJUA ME SUKSES!")
print(f"  Ekrani: {screen_w_inch:.1f}\" x {screen_h_inch:.1f}\"")
print(f"  Totali: {total_w_inch:.1f}\" x {total_h_inch:.1f}\"")
print(f"  Korniza (bezel): {bezel_inch}\"")
print("  Para: E ZEZË | Mbrapa: GRI")
print("="*50)
print("  Hap në Blender dhe shtyp F12 për render")
print("="*50)