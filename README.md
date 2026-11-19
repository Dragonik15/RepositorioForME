# Programación Estructurada: asistente con Claude

Repositorio de estudio basado en las notas del curso *Programación Estructurada en Entorno
Unix* (UAEH):

- **Unidad 5. Funciones:** concepto, alcance de variables, paso de parámetros, recursividad, funciones de `math.h`
- **Unidad 6. Apuntadores y archivos:** operaciones con apuntadores, tipos de archivos, almacenamiento secuencial y directo, apertura, lectura y escritura

Claude responde **solo** sobre estos temas (las reglas están en `CLAUDE.md`).

## Estructura

```
CLAUDE.md                  reglas y temario para Claude
material/pdf/              notas originales en PDF
material/texto/            las mismas notas en texto (para que Claude las lea)
respuestas/                soluciones y código que genere Claude
.github/workflows/claude.yml   activa a Claude en issues y comentarios
```

## Cómo pedirle algo a Claude

### Opción A: desde un issue (funciona también desde el celular)
1. Abre un **issue** nuevo.
2. Escribe tu pregunta o tarea e incluye `@claude`. Ejemplo:
   > @claude resuelve el ejercicio 3 de A.1 (conversiones de temperatura) y guárdalo en respuestas/
3. Claude contesta en el mismo issue. Si genera código, abre un pull request o te da un enlace para crearlo.
4. Para seguir la conversación, comenta en el issue con `@claude ...`.

### Opción B: Claude Code en la web
En https://claude.ai/code selecciona este repositorio y escribe tu tarea. Claude lee
`CLAUDE.md` automáticamente.

## Configuración (una sola vez)

1. Instala la app de Claude en el repositorio: https://github.com/apps/claude
2. Agrega el secreto en **Settings → Secrets and variables → Actions → New repository secret**:
   - Con suscripción Claude Pro/Max: ejecuta `claude setup-token` en tu computadora (con
     Claude Code instalado) y guarda el resultado como `CLAUDE_CODE_OAUTH_TOKEN`.
   - Con clave de API: guárdala como `ANTHROPIC_API_KEY` y, en `.github/workflows/claude.yml`,
     comenta la línea `claude_code_oauth_token` y descomenta la de `anthropic_api_key`.
